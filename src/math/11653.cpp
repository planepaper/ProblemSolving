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

    int num; cin >> num;

    while(num != 1)
    {
        for(int i = 2; i <= num; i++)
        {
            if(num % i == 0)
            {
                num /= i;
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}