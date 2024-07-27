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

    long long S; cin >> S;

    if(S == 2)
    {
        cout << 1;
        return 0;
    }

    long long root = sqrt(2 * S);

    if(S == root*(root + 1)/2)
        cout << root;
    else
    {
        for(long long i = root; i >= root - 3; i--)
        {
            long long remain = S - i * (i + 1) / 2;
            if(remain > root)
            {
                cout << i + 1;
                break;
            }
        }
    }

    return 0;
}