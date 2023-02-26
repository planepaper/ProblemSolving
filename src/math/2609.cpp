#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int a; cin >> a; int copyA = a;
    int b; cin >> b; int copyB = b;

    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    cout << a << '\n';
    cout << copyA * copyB / a  << '\n';

    return 0;
}