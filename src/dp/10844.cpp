#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int dp_all[101];
int dp[101][10][2];
const int modular = 1000000000;

void CalculateDP_ALL(int i){
    for(int j = 0; j <= 9; j++)
    {
        for(int k = 0; k <= 1; k++)
        {
            dp_all[i] += dp[i][j][k];
            dp_all[i] %= modular;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    for(int j = 1; j <= 9; j++)
    {
        for(int k = 0; k <= 1; k++)
        {
            dp[1][j][k] = 1;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        dp[i][0][0] = dp[i-1][1][0];
        for(int j = 1; j <= 8; j++)
        {
            dp[i][j][0] = dp[i-1][j-1][0] + dp[i-1][j+1][0];
        }
        dp[i][9][0] = dp[i-1][8][0];

        dp[i][1][1] = dp_all[i] + dp[i-1][2][1];
        for(int j = 2; j <= 8; j++)
        {
            dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j+1][1];
        }
        dp[i][9][1] = dp[i-1][8][1];


        CalculateDP_ALL(i);
    }

    cout << dp_all[N];

    return 0;
}