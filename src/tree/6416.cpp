#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int edgeCounts = 0;
unordered_set<int> node;
unordered_map<int, vector<int>> adj;
unordered_map<int, int> inputEdgeCounts;

bool CheckTree()
{
    if(node.size() == 0)
        return true;

    //1. n = e + 1
    if (node.size() != (edgeCounts + 1))
        return false;

    //2. only one root && 3. only input edge
    for(auto& [parent, children] : adj)
    {
        for(int i : children)
        {
            if(inputEdgeCounts.find(i) == inputEdgeCounts.end())
            {
                inputEdgeCounts.emplace(i, 1);
            }
            else
            {
                return false;
            }
        }
    }

    int rootCount = 0;
    for(auto i : node)
    {
        if(inputEdgeCounts.find(i) == inputEdgeCounts.end())
        {
            rootCount++;
        }
    }

    if(rootCount != 1)
        return false;

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

    int a, b ; cin >> a; cin >> b;

    int caseNum = 1;
    while(a != -1 || b != -1)
    {

        edgeCounts = 0; node.clear();adj.clear();inputEdgeCounts.clear();


        while(a != 0 || b != 0)
        {
            edgeCounts++;

            if (adj.find(a) != adj.end())
            {
                adj[a].push_back(b);
            }
            else
            {
                vector<int> tmp = {b};
                adj.emplace(a, tmp);
            }

            node.emplace(a);
            node.emplace(b);

            cin >> a; cin >> b;
        }

        //Printing whether it's tree or not
        if(CheckTree())
        {
            cout << "Case "<< caseNum << " is a tree." << '\n';
        }
        else
        {
            cout << "Case "<< caseNum << " is not a tree." << '\n';
        }

        caseNum++;
        cin >> a; cin >> b;
    }

    return 0;
}