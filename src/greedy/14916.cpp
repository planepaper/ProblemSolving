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

    int amount; cin >> amount;

    int fiveCoinCounts = amount / 5;
    int r = amount % 5;

    int twoCoinCounts = 0;
    if(r != 0)
    {
        if(r % 2 != 0)
        {
            fiveCoinCounts--;
            r += 5;
        }
        twoCoinCounts = r / 2;
    }

    if(amount == 1 || amount == 3)
    {
        cout << -1;
    }
    else
    {
        cout << fiveCoinCounts + twoCoinCounts;
    }

    return 0;
}