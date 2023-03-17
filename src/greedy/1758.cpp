#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> people;
deque<int> tipQue;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;
    people.reserve(counts);

    for(int i = 0; i < counts; i++)
    {
        int num; cin >> num;
        people.push_back(num);
    }

    sort(people.begin(), people.end());

    for(int i = 0, order = 0; i < counts; i++)
    {
        if(people[i] >= order)
        {
            tipQue.push_back(people[i]);
            order++;
        }
        else
        {
            tipQue.pop_front();
            tipQue.push_back(people[i]);
        }
    }

    while(tipQue.front() < (tipQue.size() - 1))
    {
        tipQue.pop_front();
    }

    long long result = 0;

    for(auto tip : tipQue)
    {
        result += tip;
    }
    result -= (tipQue.size() - 1) * tipQue.size() / 2;

    cout << result;

    return 0;
}