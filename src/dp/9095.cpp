#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int cases[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int testCounts; cin >> testCounts;

    cases[1] = 1;
    cases[2] = 2;
    cases[3] = 4;
    for(int i = 4; i < 11; i++)
    {
        cases[i] = cases[i-1] + cases[i-2] + cases[i-3];
    }


    for(int i = 0; i < testCounts; i++)
    {
        int queryNum; cin >> queryNum;
        cout << cases[queryNum] << '\n';
    }

    return 0;
}