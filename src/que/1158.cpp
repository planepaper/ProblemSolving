//
// Created by seungpyo on 2023-02-08.
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

    int size;
    cin >> size;

    queue<int> _que;

    for(int i =1;i<=size;i++)
    {
        _que.push(i);
    }

    int jumping;
    cin >> jumping;

    cout << "<";
    for(int i = 0; i < size -1 ; i++)
    {
        for(int j =0; j < jumping - 1;j++)
        {
            _que.push(_que.front());
            _que.pop();
        }
        cout << _que.front() << ", ";
        _que.pop();
    }

    cout << _que.back() << ">";

    return 0;
}