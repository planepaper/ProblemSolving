#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int testCounts; cin >> testCounts;
    for(int i = 0; i < testCounts; i++)
    {
        int numCounts; cin >> numCounts;

        vector<int> nums;
        nums.reserve(numCounts);

        for(int j = 0; j < numCounts; j++)
        {
            int num; cin >> num;
            nums.push_back(num);
        }

        vector<int> gcds;
        gcds.reserve(numCounts * (numCounts - 1) / 2);

        for(int j = 0; j < numCounts; j++)
        {
            for(int m = j + 1; m < numCounts; m++)
            {
                gcds.push_back(GCD(nums[j], nums[m]));
            }
        }

        long long sum = 0;
        for(auto it : gcds)
        {
            sum += it;
        }

        cout << sum << "\n";
    }

    return 0;
}