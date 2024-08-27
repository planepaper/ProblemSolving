#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;
int n, m;

bool seq[9];

void backtracking(int level, int index)
{
    if(level == m)
    {
        for(int i = 1 ; i <= n; i++)
        {
            if(seq[i])
                cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = index; i <= n; i++)
    {
        seq[i] = true;
        backtracking(level + 1, i + 1);
        seq[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    backtracking(0, 1);

    return 0;
}