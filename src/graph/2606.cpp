#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[101];

bool traversal[101];

void TryTraversal(int parentNode)
{
    traversal[parentNode] = true;
    for(auto childNode : graph[parentNode])
    {
        if(!traversal[childNode])
            TryTraversal(childNode);
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

        if(find(graph[a].begin(), graph[a].end(), b) == graph[a].end())
            graph[a].push_back(b);

        if(find(graph[b].begin(), graph[b].end(), a) == graph[b].end())
            graph[b].push_back(a);
    }

    TryTraversal(1);

    int answer = 0;
    for(int i = 1; i <= computerCounts; i++)
    {
        if(traversal[i])
            answer++;
    }

    cout << answer - 1;

    return 0;
}