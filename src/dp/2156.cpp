#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int wines[10000];

int dp[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> wines[i];
    }

    if(n == 1)
    {
        cout << wines[0];
        return 0;
    }
    if(n == 2)
    {
        cout << wines[0] + wines[1];
        return 0;
    }
    if(n==3)
    {
        cout << max({wines[0] + wines[2], wines[1] + wines[2], wines[0] + wines[1]});
        return 0;
    }

    dp[0] = wines[0];
    dp[1] = wines[0] + wines[1];
    dp[2] = max({wines[0] + wines[2], wines[1] + wines[2], dp[1]});
    for(int i = 3; i < n; i++)
    {
        dp[i] = max({dp[i-3] + wines[i-1] + wines[i], dp[i-2] + wines[i], dp[i-1]});
    }

    cout << dp[n-1];

    return 0;
}