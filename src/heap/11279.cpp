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

    priority_queue<int> heap;

    int rowCounts; cin >> rowCounts;

    for(int i =0; i< rowCounts; i++)
    {
        int op; cin >> op;
        int answer = 0;
        if(op == 0)
        {
            if(heap.empty())
                answer = 0;
            else
            {
                answer = heap.top();
                heap.pop();
            }
            cout << answer << '\n';
        }
        else
        {
            heap.push(op);
        }
    }


    return 0;
}