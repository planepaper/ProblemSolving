#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int dairyPrices[100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;

    for(int i = 0; i < counts; i++)
    {
        cin >> dairyPrices[i];
    }

    sort(dairyPrices, dairyPrices + counts, greater<int>());

    int answer = 0;
    for(int i = 0; i < counts/3; i++)
    {
        answer += dairyPrices[i*3 + 0];
        answer += dairyPrices[i*3 + 1];
    }

    if(counts % 3 != 0)
    {
        for(int i = 0; i< counts % 3; i++)
        {
            answer += dairyPrices[(counts/3)*3 + i];
        }
    }

    cout << answer;

    return 0;
}