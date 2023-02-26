#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int a;
int b;

long long LCM()
{
    int originA = a;
    int originB = b;

    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return (long long)originA * originB / a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int count; cin >> count;
    for(int i = 0; i< count; i++)
    {
        cin >> a; cin >> b;
        cout << LCM() << '\n';
    }

    return 0;
}