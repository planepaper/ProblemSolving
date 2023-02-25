#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int edges[100000][2];
int nodes[100001];
unordered_set<int> endNodes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif


    int nodeCounts; cin >> nodeCounts;

    for(int i = 1; i <= nodeCounts - 1; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
            nodes[edges[i][j]]++;
        }
    }

    for(int i = 1; i <= nodeCounts; i++)
    {
        if(nodes[i] == 1)
        {
            endNodes.emplace(i);
        }
    }

    int quizCounts; cin >> quizCounts;
    for(int i =0; i< quizCounts; i++)
    {
        int category; cin >> category;
        int queryIndex; cin >> queryIndex;
        if(category == 1)
        {
            if(endNodes.find(queryIndex) != endNodes.end())
            {
                cout << "no" << '\n';
            }
            else
            {
                cout << "yes" << '\n';
            }
        }
        else if(category == 2)
        {
            cout << "yes" << '\n';
        }
    }

    return 0;
}