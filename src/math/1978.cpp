#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool primeNumbers[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    for(int i = 2; i * i<= 1000; i++)
    {
        for(int j = 2; i * j <= 1000; j++)
        {
            primeNumbers[i * j] = true;
        }
    }

    primeNumbers[0] = true;
    primeNumbers[1] = true;

    int quizCounts; cin >> quizCounts;
    int count = 0;
    for(int i = 0; i < quizCounts; i++)
    {
        int num; cin >> num;
        if(!primeNumbers[num])
        {
            count++;
        }
    }

    cout << count;


    return 0;
}