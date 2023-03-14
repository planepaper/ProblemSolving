#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<char> results;

bool MakePoliomino(int xCounts)
{
    if(xCounts % 2 != 0)
    {
        results.clear();
        results.push_back('-');
        results.push_back('1');
        return false;
    }
    else
    {
        for (int j = 0; j < xCounts / 4; j++)
        {
            results.push_back('A');
            results.push_back('A');
            results.push_back('A');
            results.push_back('A');
        }
        if (xCounts % 4 == 2)

        {
            results.push_back('B');
            results.push_back('B');
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    string board; cin >> board;

    int xCounts = 0;
    for(int i = 0; i < board.length(); i++)
    {
        if(board[i] == 'X')
        {
            xCounts++;
        }
        else
        {
            if(MakePoliomino(xCounts))
            {
                results.push_back('.');
                xCounts = 0;
            }
            else
            {
                break;
            }
        }
    }

    if(xCounts != 0)
    {
        MakePoliomino(xCounts);
    }

    for(int i = 0; i < results.size(); i++)
    {
        cout << results[i];
    }

    return 0;
}