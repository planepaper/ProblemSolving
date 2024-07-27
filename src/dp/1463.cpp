#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int makeOne[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int target; cin >> target;

    makeOne[1] = 0;

    for(int i = 2; i <= target; i++)
    {
        int minNum = INT32_MAX;
        if(i % 3 == 0)
        {
            minNum = min(makeOne[i/3], minNum);
        }

        if(i % 2 == 0)
        {
            minNum = min(makeOne[i/2], minNum);
        }

        minNum = min(makeOne[i-1], minNum);

        makeOne[i] = minNum + 1;
    }

    cout << makeOne[target];

    return 0;
}