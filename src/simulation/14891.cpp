#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;
deque<int> wheel[5];
int haveToTurn[5];

void SetWheelDirection(int number, int direction)
{
    haveToTurn[number] = direction;

    //left
    for(int i = number; i > 1; i--)
    {
        if(wheel[i][6] != wheel[i-1][2])
        {
            haveToTurn[i-1] = -haveToTurn[i];
        }
        else
        {
            break;
        }
    }

    //right
    for(int i = number; i < 4; i++)
    {
        if(wheel[i][2] != wheel[i+1][6])
        {
            haveToTurn[i+1] = -haveToTurn[i];
        }
        else
        {
            break;
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

    for(int i = 1 ; i<= 4; i++)
    {
        int n; cin >> n;
        for(int j = 0; j < 8; j++)
        {
            wheel[i].push_front(n%10);
            n/=10;
        }
    }

    int count; cin >> count;

    for(int a = 0; a < count; a++)
    {
        int number; cin >> number;
        int clockwise; cin >> clockwise;

        fill(&haveToTurn[1], &haveToTurn[5], 0);
        SetWheelDirection(number, clockwise);

        for(int i = 1; i <= 4; i++)
        {
            if(haveToTurn[i] == 1)
            {
                auto back = wheel[i].back();
                wheel[i].push_front(back);
                wheel[i].pop_back();
            }
            else if(haveToTurn[i] == -1)
            {
                auto front = wheel[i].front();
                wheel[i].push_back(front);
                wheel[i].pop_front();
            }
        }
    }

    int value = 1;
    int score = 0;
    for(int i = 1; i <= 4; i++)
    {
        score += wheel[i][0] * value;
        value *= 2;
    }

    cout << score;

    return 0;
}