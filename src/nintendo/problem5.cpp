#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int,int> ants[100001];
pair<int,int> houses[100001];
pair<int,int> distances[100001];
bool placed[100001];
int result[100001];

int CalculateDistance(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first - b.first) + abs(a.second + b.second);
}

bool CmpPair(pair<int, int> a, pair<int, int> b) {

    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif


    cin >> N >> M;
    for(int i = 1 ; i<= N; i++)
    {
        cin >> ants[i].first >> ants[i].second;
    }
    for(int i = 1; i <= M; i++)
    {
        cin >> houses[i].first >> houses[i].second;
    }

    if(N<M)
    {
        for(int i= 1; i<= N; i++)
        {
            for(int j = 1; j<= M; j++)
            {
                int distance = CalculateDistance(ants[i], houses[j]);
                distances[j] = make_pair(distance, j);
            }

            sort(distances + 1, distances + 1 + M);

            for(int j = 1; j<= M; j++)
            {
                int u = distances[j].second;
                if(placed[u])
                    continue;

                result[i] = u;
                placed[u] = true;
                break;
            }
        }

        for(int i= 1; i<= N; i++)
        {
            cout << i << ' ' << result[i] << '\n';
        }
    }
    else
    {
        for(int i= 1; i<= M; i++)
        {
            for(int j = 1; j<= N; j++)
            {
                int distance = CalculateDistance(houses[i], ants[j]);
                distances[j] = make_pair(distance, j);
            }

            sort(distances + 1, distances + 1 + M);

            for(int j = 1; j<= M; j++)
            {
                int u = distances[j].second;
                if(placed[u])
                    continue;

                result[u] = i;
                placed[u] = true;
                break;
            }
        }

        for(int i= 1; i<= N; i++)
        {
            if(result[i] > 0)
            {
                cout << i << ' ' << result[i] << '\n';
            }
        }
    }




    return 0;
}