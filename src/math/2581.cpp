#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool primeNumbers[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    primeNumbers[1] = true;

    int a; cin >> a;
    int b; cin >> b;
    for(int i = 2; i * i <= b; i++)
    {
        for(int j = 2; i * j <= b; j++)
        {
            primeNumbers[i*j] = true;
        }
    }

    int primeMin = 10002;
    int sum = 0;
    for(int i = a; i <= b; i++)
    {
        if(!primeNumbers[i])
        {
            if(primeMin > i)
                primeMin = i;
            sum += i;
        }
    }

    if(primeMin == 10002)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << sum << '\n';
        cout << primeMin << '\n';
    }

    return 0;
}