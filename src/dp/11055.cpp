#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int dp[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    for(int i = 0; i< N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        int max = 0;
        for(int j= 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                if(max < dp[j])
                {
                    max = dp[j];
                }
            }
        }
        dp[i] = max + arr[i];
    }

    cout << *max_element(dp, dp + N);

    return 0;
}