#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer[9];

void backtracking(int level, int index)
{
    if(level > m)
    {
        for(int i = 1; i <=m; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = index; i <=n; i++)
    {
        answer[level] = i;
        backtracking(level+1, i);
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

    backtracking(1, 1);

    return 0;
}