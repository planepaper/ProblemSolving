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

    vector<int> nbyn;

    int n; cin >> n;

    nbyn.reserve(n*n);

    for (int i =0; i< n; i++)
    {
        for(int j =0; j<n; j++)
        {
            int num; cin >> num;
            nbyn.push_back(num);
        }
    }

    sort(nbyn.begin(), nbyn.end(), greater<int>());

    cout << nbyn[n-1];

    return 0;
}