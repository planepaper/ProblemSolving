#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

long long S;

long long CalculateSum(long long num)
{
    return num * (num + 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> S;

    long long start = 1;
    long long end = sqrt(4294967295);

    while(start <= end)
    {
        long long mid = (start + end) / 2;
        if(CalculateSum(mid) > S)
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << end;

    return 0;
}