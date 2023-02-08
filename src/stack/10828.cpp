#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cmdCounts;
    cin>>cmdCounts;

    stack<int> _stack;

    for(int i =0; i< cmdCounts;i++)
        {
         string cmd; cin >> cmd;

         if(cmd == "push")
         {
             int num; cin >> num;
            _stack.push(num);
         }
         else if(cmd == "pop")
         {
             if(_stack.empty())
             {
                 cout << -1<< '\n';
             }
             else
             {
                 int num = _stack.top();
                 _stack.pop();
                 cout << num<< '\n';
             }
         }
         else if(cmd == "size")
         {
            cout << _stack.size()<< '\n';
         }
         else if(cmd == "empty")
         {
            cout << _stack.empty() << '\n';
         }
         else if(cmd == "top")
         {
             if(_stack.empty())
             {
                 cout << -1<< '\n';
             }
             else
             {
                 cout <<  _stack.top() << '\n';
             }
         }
         else
         {

         }



    }

    return 0;
}
