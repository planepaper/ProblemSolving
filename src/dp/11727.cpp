#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int queryNum; cin >> queryNum;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= queryNum; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }

    cout << dp[queryNum];

    return 0;
}