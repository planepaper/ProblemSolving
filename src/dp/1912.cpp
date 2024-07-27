#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int arrNum;
    cin >> arrNum;

    for(int i = 1; i<= arrNum; i++)
    {
        cin >> arr[i];
    }

    int localMax = arr[1];
    int max = arr[1];
    for(int i = 2; i<= arrNum; i++)
    {
        localMax += arr[i];
        if(localMax < arr[i])
        {
            localMax = arr[i];
        }

        if(max < localMax)
        {
            max = localMax;
        }
    }

    cout << max;

    return 0;
}