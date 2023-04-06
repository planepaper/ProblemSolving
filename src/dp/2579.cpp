#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int stairScores[301];
int stairMax[301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int stairCounts; cin >> stairCounts;
    int result = 0;
    for(int i = 1; i <= stairCounts; i++)
    {
        cin >> stairScores[i];
    }
    if(stairCounts > 2)
    {
        stairMax[1] = stairScores[1];
        stairMax[2] = stairScores[1] + stairScores[2];
        for(int i = 3; i <= stairCounts; i++)
        {
            stairMax[i] = max(stairMax[i-3] + stairScores[i-1], stairMax[i-2]) + stairScores[i];
        }

        result = stairMax[stairCounts];
    }
    else
    {
        for(int i = 1; i <= stairCounts; i++)
        {
            result += stairScores[i];
        }
    }

    cout << result;

    return 0;
}