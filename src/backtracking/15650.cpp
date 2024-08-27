#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int n, m; cin >> n >> m;

    vector<int> seq(n);
    fill (seq.begin()+m, seq.end(), 1);

    do{
        for(int i = 0; i < n; i++)
        {
            if(seq[i] == 0)
            {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    } while(next_permutation(seq.begin(), seq.end()));

    return 0;
}