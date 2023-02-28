#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool notPrimeNumbers[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int numCounts; cin >> numCounts;

    vector<int> numbers;
    numbers.reserve(numCounts);

    int max = 0;
    for(int i = 0; i< numCounts; i++)
    {
        int num; cin >> num;
        if(max < num) max = num;
        numbers.push_back(num);
    }


    for(int i = 2; i<= max/2; i++)
    {
        for(int j = 2; i*j <= max && !notPrimeNumbers[i]; j++)
        {
            notPrimeNumbers[i*j] = true;
        }
    }

    long long answer = 1;
    for(int i = 0; i<numCounts; i++)
    {
        if(!notPrimeNumbers[numbers[i]] && answer % numbers[i] != 0)
        {
            answer *= numbers[i];
        }
    }

    if(answer == 1)
    {
        answer = -1;
    }

    cout << answer;

    return 0;
}