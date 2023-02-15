//
// Created by 승표손 on 2023/02/15.
//
#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

void SolvingProblem(deque<int>& _queue, deque<int>& orderQueue, int findingIndex)
{
    int _queueSize = _queue.size();

    for(int i =1; i<= _queueSize; i++)
    {
        int maxNum = -1;
        for(auto it = _queue.cbegin(); it != _queue.cend(); it++)
        {
            if(*it > maxNum)
            {
                maxNum = *it;
            }
        }

        //finding max
        while(_queue.front() != maxNum)
        {
            _queue.push_back(_queue.front());
            orderQueue.push_back(orderQueue.front());

            _queue.pop_front();
            orderQueue.pop_front();
        }

        if(orderQueue.front() == findingIndex)
        {
            cout << i << '\n';
        }

        _queue.pop_front();
        orderQueue.pop_front();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt","r",stdin);
#endif

    int problemCounts; cin >> problemCounts;

    for (int i = 0;i < problemCounts; i++)
    {
        int elementConuts; cin >> elementConuts;
        int findingIndex; cin >> findingIndex;

        deque<int> _que;
        deque<int> orderQueue;

        for (int j=0; j< elementConuts; j++)
        {
            int element; cin >> element;

            _que.push_back(element);
            orderQueue.push_back(j);
        }

        SolvingProblem(_que, orderQueue, findingIndex);
    }
}
