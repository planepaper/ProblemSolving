#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool primeNumbers[1001];

int num;
int counts;

int GetAnswer()
{
    int index = 0;
    for(int i = 2; i <= num; i++)
    {
        for(int j = 1; i * j <= num; j++)
        {
            if(!primeNumbers[i*j])
            {
                primeNumbers[i*j]= true;
                index++;
            }

            if(index == counts)
            {
                return i*j;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> num;
    cin >> counts;

    cout << GetAnswer();

    return 0;
}