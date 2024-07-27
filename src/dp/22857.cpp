#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    vector<int> evenSeq;

    int numCounts; cin >> numCounts;
    int deleteCounts; cin >> deleteCounts;

    int evenCounts = 0;
    for(int i = 0; i <numCounts; i++) {
        int num;
        cin >> num;
        if (num % 2) {
            //odd
            evenSeq.push_back(evenCounts);
            evenCounts = 0;
        }
        else {
            evenCounts++;
        }
    }
    evenSeq.push_back(evenCounts);

    deleteCounts = min((int)evenSeq.size() - 1, deleteCounts);

    vector<int> evenSum(evenSeq.size() - deleteCounts);
    int sum = 0;
    for(int i = 0; i <= deleteCounts; i++)
    {
        sum += evenSeq[i];
    }
    evenSum[0] = sum;

    for(int i = 1; i < evenSum.size(); i++)
    {
        evenSum[i] = evenSum[i-1] - evenSeq[i-1] + evenSeq[i+deleteCounts];
    }

    cout << *max_element(evenSum.begin(), evenSum.end());

    return 0;
}