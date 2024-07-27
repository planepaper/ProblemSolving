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

    int weight, height, bmi;
    cin >> weight >> height >> bmi;

    double targetWeight = bmi * height * height / 10000.0;
    double need = targetWeight - weight;

    if(need < 0)
    {
        cout << 0;
    }
    else
    {
        cout << (int)ceil(need);
    }

    return 0;
}