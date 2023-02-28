#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int numCounts; cin >> numCounts;
    for(int i = 0; i< numCounts; i++)
    {
        unsigned int num; cin >> num;
        unsigned int answer = num;

        for(unsigned int j = num; ; j++)
        {
            bool isPrime = true;
            for(unsigned int k = 2; k*k <= j; k++)
            {
                if(j % k == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if(isPrime)
            {
                answer = j;
                break;
            }
        }

        if(num == 1 || num == 0)
        {
            answer = 2;
        }

        cout << answer << '\n';
    }

    return 0;
}