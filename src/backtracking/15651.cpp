#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> stk;
int n, m;

void backtracking(int level)
{
    if(level >= m)
    {
        for(auto i : stk)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        stk.push_back(i);
        backtracking(level+1);
        stk.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    stk.reserve(8);

    backtracking(0);

    return 0;
}