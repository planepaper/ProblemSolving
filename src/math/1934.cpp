#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int CalculateLCM(int a, int b)
{
    int copyA = a; int copyB = b;

    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return copyA * copyB / a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int caseCounts; cin >> caseCounts;

    for(int i =0; i< caseCounts; i++)
    {
        int a; cin >> a;
        int b; cin >> b;
        cout << CalculateLCM(a, b) << '\n';
    }

    return 0;
}