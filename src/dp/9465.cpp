#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int stickers[100001][2];
int dp[100001][2];

int problem()
{
    int rowCounts; cin >> rowCounts;

    for(int j = 0; j< 2; j++)
    {
        for(int i = 1; i<= rowCounts; i++)
        {
            cin >> stickers[i][j];
        }
    }


    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = stickers[1][0];
    dp[1][1] =  stickers[1][1];

    for(int i = 2; i <= rowCounts; i++)
    {
        dp[i][0] = stickers[i][0] + max(dp[i-2][1], dp[i-1][1]);
        dp[i][1] = stickers[i][1] + max(dp[i-2][0], dp[i-1][0]);
    }

    return max(dp[rowCounts][0], dp[rowCounts][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int problemCounts; cin >> problemCounts;

    for(int i = 0; i <problemCounts; i++)
    {
        cout << problem() << '\n';
    }

    return 0;
}