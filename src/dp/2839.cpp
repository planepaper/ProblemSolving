#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int bagCounts[5001];

int main()
{
#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif
    bagCounts[1] = -1;
    bagCounts[2] = -1;
    bagCounts[3] = 1;
    bagCounts[4] = -1;
    bagCounts[5] = 1;

    int target; cin >> target;
    for(int i = 6; i <= target; i++)
    {
        if(bagCounts[i - 3] == -1 && bagCounts[i - 5] == -1)
        {
            bagCounts[i] = -1;
        }
        else if (bagCounts[i - 3] == -1)
        {
            bagCounts[i] = bagCounts[i-5] + 1;
        }
        else if(bagCounts[i - 5] == -1)
        {
            bagCounts[i] = bagCounts[i-3] + 1;
        }
        else
        {
            bagCounts[i] = min(bagCounts[i-3], bagCounts[i-5]) + 1;
        }
    }

    cout << bagCounts[target];

    return 0;
}