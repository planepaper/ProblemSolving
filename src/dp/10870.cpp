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

    int targetOrder; cin >> targetOrder;

    int f_n0 = 0;
    int f_n1 = 1;
    int f_n2;
    for(int i = 2; i <= targetOrder; i++)
    {
        f_n2 = f_n0 + f_n1;
        f_n0 = f_n1;
        f_n1 = f_n2;
    }

    if(targetOrder == 0) f_n2 = 0;
    if(targetOrder == 1) f_n2 = 1;

    cout << f_n2;

    return 0;
}