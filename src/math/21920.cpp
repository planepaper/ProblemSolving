#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int numbers[500000];

int GCD(int a, int b)
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

    int numCounts; cin >> numCounts;

    for(int i = 0; i<numCounts; i++)
    {
        cin >> numbers[i];
    }

    int quiz; cin >> quiz;

    long long sum = 0;
    int coprimeCounts = 0;
    for(int i =0; i< numCounts; i++)
    {
        if(GCD(numbers[i], quiz) == 1)
        {
            sum += numbers[i];
            coprimeCounts++;
        }
    }

    cout << sum / (double)coprimeCounts;

    return 0;
}