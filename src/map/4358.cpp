#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    map<string, int> trees;

    string treeName;
    int treeCounts = 0;
    while(getline(cin, treeName))
    {
        trees[treeName]++;
        treeCounts++;
    }

    cout.precision(4);
    cout << fixed;
    for(auto &it : trees)
    {
        cout << it.first << ' ' << it.second * 100.0 / treeCounts  << '\n';
    }

    return 0;
}