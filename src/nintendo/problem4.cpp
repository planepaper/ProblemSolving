#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int m, n;
int pathCount = 0;
bool visited[4][4];

void dfs(int level, int x, int y)
{
    if(x < 0 || x >= m)
        return;
    if(y < 0 || y >= n)
        return;
    if(visited[x][y])
        return;

    visited[x][y]= true;

    if(level == m*n)
    {
        pathCount++;
    }

    dfs(level + 1, x+1, y);
    dfs(level + 1, x-1, y);
    dfs(level + 1, x, y+1);
    dfs(level + 1, x, y-1);
    visited[x][y]= false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> m >> n;

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            dfs(1, i, j);
            memset(visited, 0, sizeof(visited));
        }
    }

    cout << pathCount;

    return 0;
}