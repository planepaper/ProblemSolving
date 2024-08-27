#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int row, col, x, y, inst;
int board[20][20];

deque<int> vertical;
deque<int> horizontal;

bool TryToMove(int move)
{
    int newX = x, newY = y;
    //east
    if(move == 1)
    {
        newY += 1;
    }
    //west
    else if(move == 2)
    {
        newY -= 1;
    }
    //north
    else if(move == 3)
    {
        newX -= 1;
    }
    //south
    else if(move == 4)
    {
        newX += 1;
    }

    if(newX >= 0 && newX < row && newY >= 0 && newY < col)
    {
        x = newX; y = newY;
        return true;
    }

    return false;
}

void RunCopyInstruction()
{
    if(board[x][y] != 0)
    {
        horizontal[1] = board[x][y];
        vertical[1] = board[x][y];
        board[x][y] = 0;
    }
    else
    {
        board[x][y] = horizontal[1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> row >> col >> x >> y >> inst;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }

    //initialize
    for(int i = 0; i< 4; i++)
    {
        horizontal.push_back(0);
        vertical.push_back(0);
    }

    for(int i = 0; i < inst; i++)
    {
        int move; cin >> move;

        if(TryToMove(move))
        {
            //east
            if(move == 1)
            {
                auto front = horizontal.front();
                horizontal.pop_front();
                horizontal.push_back(front);
                vertical[1] = horizontal[1];
                vertical[3] = horizontal[3];

                RunCopyInstruction();
            }
            //west
            else if(move ==2)
            {
                auto back = horizontal.back();
                horizontal.pop_back();
                horizontal.push_front(back);
                vertical[1] = horizontal[1];
                vertical[3] = horizontal[3];

                RunCopyInstruction();
            }
            //north
            else if(move ==3)
            {
                auto back = vertical.back();
                vertical.pop_back();
                vertical.push_front(back);
                horizontal[1] = vertical[1];
                horizontal[3] = vertical[3];

                RunCopyInstruction();
            }
            //south
            else if(move ==4)
            {
                auto front = vertical.front();
                vertical.pop_front();
                vertical.push_back(front);
                horizontal[1] = vertical[1];
                horizontal[3] = vertical[3];

                RunCopyInstruction();
            }

            cout << horizontal[3] << '\n';
        }
    }



    return 0;
}