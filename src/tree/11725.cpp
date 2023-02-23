#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool visited[100001];
int parents[100001];

void PreorderTraversal(int parentIndex)
{
    visited[parentIndex] = true;

    for(int childIndex : adj[parentIndex])
    {
        if(!visited[childIndex])
        {
            parents[childIndex] = parentIndex;
            PreorderTraversal(childIndex);
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

    //making adj
    int nodeCounts; cin >> nodeCounts;
    for(int i = 0; i < nodeCounts - 1; i++)
    {
        int a, b; cin >> a; cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //traversal
    PreorderTraversal(1);

    for(int i = 2; i<= nodeCounts; i++)
    {
        cout << parents[i] << '\n';
    }

    return 0;
}