//
// Created by 승표손 on 2023/02/10.
//
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

    int cmdCounts; cin >> cmdCounts;

    deque<int> _deque;

    for(int i =0; i < cmdCounts; i++)
    {
        string cmd; cin >> cmd;

        if(cmd == "push_front")
        {
            int item; cin >> item;
            _deque.push_front(item);
        }
        else if(cmd == "push_back")
        {
            int item; cin >> item;
            _deque.push_back(item);
        }
        else if(cmd == "pop_front")
        {
            if(_deque.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << _deque.front() << '\n';
                _deque.pop_front();
            }
        }
        else if(cmd == "pop_back")
        {
            if(_deque.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << _deque.back() << '\n';
                _deque.pop_back();
            }
        }
        else if(cmd == "size")
        {
            cout << _deque.size() << '\n';
        }
        else if(cmd == "empty")
        {
            cout << _deque.empty()<< '\n';
        }
        else if(cmd == "front")
        {
            if(_deque.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << _deque.front() << '\n';
            }
        }
        else if(cmd == "back")
        {
            if(_deque.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << _deque.back() << '\n';
            }
        }
    }
    return 0;
}


