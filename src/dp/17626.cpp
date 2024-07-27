#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int fourSquares[50001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    fourSquares[0] = 0;

    int target; cin >> target;



    for(int i = 1; i <= target; i++)
    {
        int min = 5;
        int maxSqrt = (int)sqrt(i);
        int minSqrt = (int)sqrt(i - maxSqrt * maxSqrt);
        for(int j = maxSqrt; j >= minSqrt; j-- )
        {
            int remain = i - j * j;
            if(remain == 0)
            {
                min = 1;
                break;
            }
            else if(fourSquares[remain] != 0 && fourSquares[remain] + 1 < min)
            {
                min = fourSquares[remain] + 1;
            }
        }
        fourSquares[i] = min;
    }

    cout << fourSquares[target];

    return 0;
}