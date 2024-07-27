#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int arr[10];
int choose[10];
int N, M;
unordered_set<string> a;

void dfs(int level)
{
    if(level == M)
    {
        for(int i = 0; i< M;i++)
        {
            cout << choose[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < N; i++)
    {
        if(level > 0 && choose[level-1] > arr[i])
            continue;
        if(choose[level] == arr[i])
            continue;

        choose[level] = arr[i];

        dfs(level + 1);
    }
    choose[level] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    dfs(0);

    return 0;
}