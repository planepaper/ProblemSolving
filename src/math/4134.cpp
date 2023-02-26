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
        int num; cin >> num;
        int answer = num;
        for(unsigned int j = num + 1; j <= 4000000000; j++)
        {
            bool isPrime = true;
            for(unsigned int k = 2; k < j; k++)
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
        cout << answer << '\n';
    }

    return 0;
}