//
// Created by seungpyo on 2023-02-08.
//
#include <bits/stdc++.h>

using namespace std;

string CheckRow(string row)
{
    stack<int> _stack;

    for(int i =0; i<row.length();i++)
    {
        if(row[i] == '(')
        {
            _stack.push(1);
        }
        else if(row[i] == ')')
        {
            if(_stack.empty())
            {
                return "NO";
            }
            _stack.pop();
        }
    }
    if(!_stack.empty())
    {
        return  "NO";
    }
    return  "YES";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cmdCounts; cin >> cmdCounts;
    for(int i =0;i<cmdCounts;i++)
    {
        string row; cin >> row;
        cout << CheckRow(row) << '\n';
    }

    return 0;
}
