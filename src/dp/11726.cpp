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
    long long rectangles[1001];

    rectangles[1] = 1;
    rectangles[2] = 2;

    int queryNum; cin >> queryNum;

    for(int i = 3; i <= queryNum; i++)
    {
        rectangles[i] = (rectangles[i-1] + rectangles[i-2]) % 10007;
    }
    cout << rectangles[queryNum] << '\n';

    return 0;
}