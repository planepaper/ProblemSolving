#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;

    vector<int> ropes;
    ropes.reserve(counts);

    for(int i = 0; i< counts; i++)
    {
        int ropeCapacity;
        cin >> ropeCapacity;
        ropes.push_back(ropeCapacity);
    }

    sort(ropes.begin(), ropes.end());

    int max = 0;
    for(int i = 0; i < counts; i++)
    {
        int temp = ropes[i] * (counts-i);

        if(max< temp) max = temp;
    }

    cout << max;

    return 0;
}