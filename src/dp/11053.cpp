#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int nums[1000];
int dp[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;

    for(int i = 0; i < counts; i++)
    {
        cin >> nums[i];
    }

    for(int i = 0; i < counts; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + counts);

    return 0;
}