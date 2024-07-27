#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[10001];

bool checked[10001];
bool visited[10001];

int counts[10001];

int hackCount = 0;

void DFS(int parentNode)
{
    visited[parentNode] = true;
    checked[parentNode] = true;
    hackCount++;
    for(auto childNode : graph[parentNode])
    {
        if(!visited[childNode])
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

    int computerCounts; cin >> computerCounts;
    int pairCounts; cin >> pairCounts;

    for(int i = 0; i< pairCounts; i++)
    {
        int a; cin >> a;
        int b; cin >> b;

        graph[b].push_back(a);

    }

    for(int i = 1; i <= computerCounts; i++)
    {
        hackCount = 0;
        memset(visited, false, sizeof(visited));

        DFS(i);
        counts[i] = hackCount;
    }

    int max = *max_element(counts+1, counts+computerCounts+1);

    for(int i = 1; i <= computerCounts; i++)
    {
        if(counts[i] == max)
            cout << i << ' ';
    }

    return 0;
}