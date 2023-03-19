#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int timesOfPeople[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;

    for(int i = 0; i < counts; i++)
    {
        cin >> timesOfPeople[i];
    }

    sort(timesOfPeople, timesOfPeople+counts);

    long long result = 0;
    for(int i =0; i< counts; i++)
    {
        result += timesOfPeople[i] * (counts - i);
    }

    cout << result;

    return 0;
}