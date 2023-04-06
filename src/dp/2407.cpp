#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

string dp[101][101];

string AddStringNum(string a, string b)
{
    string answer = "";
    int minCount = min(a.length(), b.length());

    if(a.length()> b.length())
    {
        for(int i = b.length(); i < a.length(); i++)
        {
            b = "0" + b;
        }
    }
    else
    {
        for(int i = a.length(); i < b.length(); i++)
        {
            a = "0" + a;
        }
    }

    bool addFlag = false;
    for(int i = a.length() - 1; i >=0 ; i--)
    {
        int temp = (a[i] - '0') + (b[i] - '0');
        if(addFlag)
        {
            temp++;
        }
        if(temp / 10 == 1)
        {
            addFlag = true;
        }
        else
        {
            addFlag = false;
        }
        answer = to_string(temp%10) + answer;
    }

    if(addFlag)
    {
        answer = "1" + answer;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie();

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;
    int m; cin >> m;

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = "1";
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = AddStringNum(dp[i-1][j-1], dp[i-1][j]);
        }
        dp[i][i] = "1";
    }

    cout << dp[n][m];

    return 0;
}