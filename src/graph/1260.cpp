#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];

deque<int> reserveNode;

bool dfsVisited[1001];
bool bfsVisited[1001];

void DFS(int parentNode)
{
    dfsVisited[parentNode] = true;
    cout << parentNode << ' ';
    for(auto childNode : graph[parentNode])
    {
        if(!dfsVisited[childNode])
            DFS(childNode);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int nodeCounts; cin >> nodeCounts;
    int pairCounts; cin >> pairCounts;
    int startNode; cin >> startNode;

    for(int i = 0; i< pairCounts; i++)
    {
        int a; cin >> a;
        int b; cin >> b;

        if(find(graph[a].begin(), graph[a].end(), b) == graph[a].end())
            graph[a].push_back(b);

        if(find(graph[b].begin(), graph[b].end(), a) == graph[b].end())
            graph[b].push_back(a);
    }

    for(int i = 1; i<= nodeCounts; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(startNode);
    cout << '\n';

    bfsVisited[startNode] = true;
    reserveNode.push_back(startNode);
    while(!reserveNode.empty())
    {
        int parentNode = reserveNode.front();
        reserveNode.pop_front();
        cout << parentNode << ' ';

        for(auto childNode : graph[parentNode])
        {
            if(!bfsVisited[childNode])
            {
                bfsVisited[childNode] = true;
                reserveNode.push_back(childNode);
            }
        }
    }

    return 0;
}