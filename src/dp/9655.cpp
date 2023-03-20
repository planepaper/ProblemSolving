#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;

    if(counts % 2 == 1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }

    return 0;
}