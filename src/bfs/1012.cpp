#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int row, col;
bool field[50][50];
bool visited[50][50];
vector<pair<int, int>> crops;

vector<pair<int,int>> bfs(vector<pair<int,int>> start)
{
    queue<pair<int,int>> will;
    will.push(start);
    visited[start.first][start.second] = true;
    while(!will.empty())
    {
        pair<int,int> lets = will.front();
        will.pop();
        vector<pair<int, int>> possible(4);
        possible.emplace_back(lets.first-1, lets.second);
        possible.emplace_back(lets.first, lets.second - 1);
        possible.emplace_back(lets.first, lets.second + 1);
        possible.emplace_back(lets.first+1, lets.second);

        for(auto i : possible)
        {
            int x = i.first;
            int y = i.second;
            if(x >= 0 && x < row && y >= 0 && y < col)
            {
                if(field[x][y] && !visited[x][y])
                {
                    will.emplace(x, y);
                    visited[x][y] = true;
                }
            }
        }
    }

    vector<pair<int,int>> a;
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int cases; cin >> cases;
    for(int i = 0; i< cases; i++)
    {
        int cropCounts; cin >> row >> col >> cropCounts;
        vector<pair<int, int>> crops1;
        crops1.emplace_back(1,1);
        vector<pair<int, int> > crops2(crops1);
        pair<int, int> start = {1,1}; // 복사생성자 호출

        crops1 = crops; // 대입연사자 호출 -> 복사생성자 호출 -> 깊은복사 이뤄짐

        c++14 이후부터는 컴파일러
        vector<pair<int,int>> i = bfs();     // 복사생성자호출

        pair<int,int>a = {1, 1};
        pair<int,int>b({1, 1});




        for(int i = 0; i < cropCounts; i++)
        {
            int x, y; cin >> x >> y;
            field[x][y] = true;
        }

        int worms = 0;
        for(int i = 0; i < cropCounts; i++)
        {
            if(!visited[crops[i].first][crops[i].second])
            {
                worms++;
                bfs(crops);
            }
        }
        cout << worms << '\n';

        fill(&field[0][0], &field[row-1][col], false);
        fill(&visited[0][0], &visited[row-1][col], false);
        crops.clear();
    }

    return 0;
}