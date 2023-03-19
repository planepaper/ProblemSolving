#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int timesOfPeople[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int coinCounts; cin >> coinCounts;
    int targetNum; cin >> targetNum;

    vector<int> coinKinds;

    for(int i = 0; i< coinCounts; i++)
    {
        int num; cin >> num;
        coinKinds.push_back(num);
    }

    int answer = 0;
    for(int i = coinCounts - 1; i >= 0; i-- )
    {
        if(targetNum / coinKinds[i] > 0)
        {
            answer += targetNum / coinKinds[i];
            targetNum %= coinKinds[i];
        }
    }

    cout << answer;

    return 0;
}