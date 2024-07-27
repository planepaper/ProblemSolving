#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N, M;
list<pair<int,int>> adj[201]; // (v, weight)
int dist[201][201];
typedef pair<int, int> Weight_u;
priority_queue <Weight_u, vector<Weight_u>, greater<Weight_u>> ableVertex;
int path[201][201];

int result[201][201];

void dijkstra(int src)
{
    ableVertex = priority_queue <Weight_u, vector<Weight_u>, greater<Weight_u>>();
    fill(dist[src] + 1, dist[src]+ 1 + N, INF);

    dist[src][src] = 0;
    ableVertex.push(make_pair(0, src));

    while (!ableVertex.empty())
    {
        int u = ableVertex.top().second;
        ableVertex.pop();

        for (auto& i: adj[u]) {
            int v = i.first;
            int weight = i.second;

            if (dist[src][v] > dist[src][u] + weight) {
                dist[src][v] = dist[src][u] + weight;
                ableVertex.push(make_pair(dist[src][v], v));

                path[src][v] = u;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }


    for(int i = 1; i <= N; i++)
    {
        dijkstra(i);
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int now = j;
            int before = j;
            while(now != i)
            {
                before = now;
                now = path[i][now];
            }
            result[i][j] = before;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(i == j)
                cout << '-' << ' ';
            else
                cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}