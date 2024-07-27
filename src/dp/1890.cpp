#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int square;
int board[100][100];
long long dp[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> square;

    for(int i = 0; i < square; i++)
    {
        for(int j = 0; j < square; j++)
        {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < square; i++)
    {
        for(int j = 0; j < square; j++)
        {
            if(dp[i][j] == 0)
                continue;

            int jump = board[i][j];
            if(jump == 0)
                break;
            if(j+jump < square)
                dp[i][j+jump] += dp[i][j];
            if(i+jump < square)
                dp[i+jump][j] += dp[i][j];
        }
    }

    cout << dp[square-1][square-1];

    return 0;
}