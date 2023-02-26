#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int num;

void DoOneCycle()
{
    num = num % 10 * 10 + (num / 10 + num % 10) % 10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> num; int originNum = num;

    int count = 0;
    do {
        DoOneCycle();
        count++;
    }
    while(originNum != num);

    cout << count;

    return 0;
}