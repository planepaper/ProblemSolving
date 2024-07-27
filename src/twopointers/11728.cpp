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

    int aLength; cin >> aLength;
    int bLength; cin >> bLength;

    vector<int> arr(aLength+bLength);
    for(int i =0; i< arr.size(); i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i =0; i< arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}