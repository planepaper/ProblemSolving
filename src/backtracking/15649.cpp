#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int choose[10], N, M;
bool used[10];

void dfs(int level) {
    if(level == M)
    {
        for(int i = 0; i< M; i++)
        {
            cout << choose[i] << ' ';
        }
        cout << '\n';
    }

    for(int i = 1 ; i <= N; i++)
    {
        if(used[i])
            continue;

        used[i] = true;

        choose[level] = i;

        dfs(level + 1);

        used[i] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    dfs(0);

    return 0;
}