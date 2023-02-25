#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int buildings[1024];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int level; cin >> level;


    int maxSize = pow(2, level);

    for(int i = 1; i < maxSize; i++)
    {
        cin >> buildings[i];
    }

    for(int i = 1; i <= level; i++)
    {
        int divOperand = pow(2,i);

        for(int j = 1; j< divOperand; j += 2)
        {
            int index = maxSize * j / divOperand;
            cout << buildings[index] << ' ';
        }
        cout << '\n';
    }

    return 0;
}