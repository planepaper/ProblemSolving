#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

long long combinations[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    for(int i = 1; i <= 30; i++)
    {
        for(int j = 0; j<= i; j++)
        {
            if(j == 0 || j == i)
            {
                combinations[i][j] = 1;
                continue;
            }

            combinations[i][j] = combinations[i-1][j-1] + combinations[i-1][j];
        }
    }

    int testCounts; cin >>testCounts;
    for(int i = 0; i< testCounts; i++)
    {
        int leftCounts; cin >> leftCounts;
        int rightCounts; cin >> rightCounts;

        cout << combinations[rightCounts][leftCounts] << '\n';
    }


    return 0;
}