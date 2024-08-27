#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Coordinate;

char board[12][6];
bool visited[12][6];
bool removed[12][6];

vector<Coordinate> path;

void bfs(Coordinate start)
{
    queue<Coordinate> willVisited;
    visited[start.first][start.second]= true;
    willVisited.push(start);
    path.push_back(start);

    char key = board[start.first][start.second];

    while(!willVisited.empty())
    {
        auto front = willVisited.front();
        willVisited.pop();

        int row = front.first;
        int col = front.second;

        Coordinate possible[4] = {
                {row - 1,col},
                {row + 1, col},
                {row, col - 1},
                {row, col + 1},
        };

        for(auto& i : possible)
        {
            auto irow = i.first;
            auto icol = i.second;
            if(irow >= 0 && irow < 12 && icol >= 0 && icol < 6
            && board[irow][icol] == key
            && !visited[irow][icol])
            {
                visited[irow][icol]= true;
                willVisited.push(i);
                path.push_back(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    for(int i = 0; i < 12; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j < 6; j++)
        {
            board[i][j] = a[j];
        }
    }

    bool flag = true;
    int count = 0;
    while(flag)
    {
        flag= false;
        fill(&visited[0][0], &visited[11][6], false);
        fill(&removed[0][0], &removed[11][6], false);

        //count
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(board[i][j] != '.')
                {
                    path.clear();
                    bfs({i,j});
                    if(path.size() >=4)
                    {
                        for(auto& k : path)
                        {
                            removed[k.first][k.second] = true;
                        }
                        flag = true;
                    }
                }
            }
        }

        if(flag)
        {
            count++;
            char newboard[12][6];
            fill(&newboard[0][0], &newboard[11][6], '.');
            for(int j = 0; j < 6; j++)
            {
                int index = 11;
                for(int i = 11; i >= 0; i--)
                {
                    if(!removed[i][j])
                    {
                        newboard[index][j] = board[i][j];
                        index--;
                    }
                }
            }
            copy(&newboard[0][0], &newboard[11][6], &board[0][0]);
        }
    }

    cout << count;


    return 0;
}