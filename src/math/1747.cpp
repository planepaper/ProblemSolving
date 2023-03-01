#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool notPrimeNumbers[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    notPrimeNumbers[1] = true;
    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = 2; i*j <= 2000000; j++)
        {
            notPrimeNumbers[i*j] = true;
        }
    }

    int quiz; cin >> quiz;
    int answer;
    for(int i = quiz; ; i++)
    {
        if(!notPrimeNumbers[i])
        {
            string originNum = to_string(i);
            string reverseNum = originNum;
            reverse(originNum.begin(), originNum.end());
            if(originNum == reverseNum)
            {
                answer = i;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}