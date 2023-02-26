#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int FindGCD(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int numCounts = 0; cin >> numCounts;

    int nums[3] = {0,};

    for(int i =0; i < numCounts; i++)
    {
        cin >> nums[i];
    }

    for(int i =0; i < numCounts -1; i++)
    {
        nums[i+1] = FindGCD(nums[i], nums[i+1]);
    }

    int gcd = nums[numCounts - 1];

    for(int i = 1; i <= gcd; i++)
    {
        if(gcd % i == 0)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
