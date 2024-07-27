#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int n;
int graph[125][125];
pair<int,int> path[125][125];
int cost[125][125];

const int INF = 1e9;

typedef tuple<int, int, int> Cost_x_y;
priority_queue <Cost_x_y, vector<Cost_x_y>, greater<Cost_x_y>> ableVertex;

void UpdateCost(int u_x, int u_y, int v_x, int v_y)
{
    if(v_x < 0 || v_x >= n)
        return;
    if(v_y < 0 || v_y >= n)
        return;

    int weight = graph[v_x][v_y];

    if (cost[v_x][v_y] > cost[u_x][u_y] + weight) {
        cost[v_x][v_y] = cost[u_x][u_y] + weight;
        path[v_x][v_y] = make_pair(u_x, u_y);

        ableVertex.push(make_tuple(cost[v_x][v_y] , v_x, v_y));
    }
}

void dijkstra()
{
    path[0][0] = make_pair(0,0);
    cost[0][0] = graph[0][0];

    ableVertex.push(make_tuple(0,0,0));

    while(ableVertex.size())
    {
        int x = get<1>(ableVertex.top());
        int y = get<2>(ableVertex.top());
        ableVertex.pop();

        UpdateCost(x, y, x-1, y);
        UpdateCost(x, y, x+1, y);
        UpdateCost(x, y, x, y-1);
        UpdateCost(x, y, x, y+1);
    }
}

void Solve(int problemNum)
{
    memset(graph, 0, sizeof(graph));
    memset(path, 0, sizeof(path));
    fill(&cost[0][0], &cost[n-1][n], INF);


    for(int i = 0 ; i< n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            cin >> graph[i][j];
        }
    }

    dijkstra();
    cout << "Problem " << problemNum << ": " << cost[n-1][n-1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int problemNum = 1;
    cin >> n;
    while(n != 0)
    {
        Solve(problemNum);
        problemNum++;
        cin >> n;
    }


    return 0;
}