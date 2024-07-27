#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> edge[1001];

int graph[1001][1001];
int degrees[1001];

int N;
vector<int> path;

void dfs(int node)
{
    for(int i = 1; i<=N;i++)
    {
        while(graph[node][i] > 0)
        {
            graph[node][i]--;
            graph[i][node]--;
            dfs(i);
        }
    }

    path.push_back(node);
}

bool CheckEulerCircuit()
{
    for(int i = 1; i <= N; i++)
    {
        if(degrees[i] % 2)
        {
            return false;
        }
    }
    return true;
}

bool CheckNoEdgesLeft()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(graph[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int degree; cin >> degree;
            while(degree--)
            {

            }
            cin >> graph[i][j];
            degrees[i] += graph[i][j];
        }
    }


    dfs(4);
    reverse(path.begin(), path.end());
    for(int node : path)
    {
        cout << node << ' ';
    }

    return 0;
}