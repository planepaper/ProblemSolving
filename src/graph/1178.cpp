#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int node[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int V; cin >> V;
    int E; cin >> E;

    for(int i = 0; i< E;i++)
    {
        int a, b; cin >> a >> b;
        node[a]++;
        node[b]++;
    }

    int zeroCounts = 0;
    int oddCounts = 0;
    int evenCounts = 0;
    for(int i =1; i<= V; i++)
    {
        if(node[i] == 0)
        {
            zeroCounts++;
        }
        else if(node[i] % 2 == 1)
        {
            oddCounts++;
        }
        else
        {
            evenCounts++;
        }
    }

    int answer = 0;
    if(oddCounts != 0)
    {
        answer += oddCounts / 2 - 1;
    }

    if(zeroCounts != 0)
    {
        answer += zeroCounts + 1;
    }

    cout <<  answer;

    return 0;
}