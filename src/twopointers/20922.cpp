#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int arr[200001];
int same[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    int sameCounts; cin >> sameCounts;

    for(int i = 1; i<= N; i++)
    {
        cin >> arr[i];
    }

    int serialCount = 0;
    int max = 0;
    for(int start = 1, end = 1; end <= N; end++)
    {
        same[arr[end]]++;
        serialCount++;
        while(same[arr[end]] > sameCounts)
        {
            same[arr[start]]--;
            serialCount--;
            start++;
        }

        if(max < serialCount)
            max = serialCount;
    }

    cout << max;

    return 0;
}