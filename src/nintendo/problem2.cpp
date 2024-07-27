#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x;
    int y;
};

struct Vector3{
    int x;
    int y;
};

Point squareA[4];
Point squareB[4];

double pointA_To_SquareB[4];
double pointB_To_SquareA[4];

bool flagA[4];
bool flagB[4];

double GetTriangleArea(Point dot1, Point dot2, Point dot3)
{
    double first = dot1.x * dot2.y + dot2.x * dot3.y + dot3.x * dot1.y;
    double second = dot1.y * dot2.x + dot2.y * dot3.x + dot3.y * dot1.x;

    return abs(first - second) / 2.0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    for(int i= 0; i < 4; i++)
    {
        cin >> squareA[i].x >> squareA[i].y;
    }
    for(int i= 0; i < 4; i++)
    {
        cin >> squareB[i].x >> squareB[i].y;
    }

    double areaA = GetTriangleArea(squareA[0],squareA[1],squareA[2])
            + GetTriangleArea(squareA[2],squareA[3], squareA[0]);
    double areaB = GetTriangleArea(squareB[0],squareB[1],squareB[2])
                + GetTriangleArea(squareB[2],squareB[3], squareB[0]);


    int count = 0;
    bool collisioned = false;
    bool onSide = false;
    for(int i = 0; i< 4; i++)
    {
        double t[4];
        t[0] = GetTriangleArea(squareA[0], squareA[1], squareB[i]);
        t[1] = GetTriangleArea(squareA[1], squareA[2], squareB[i]);
        t[2] = GetTriangleArea(squareA[2], squareA[3], squareB[i]);
        t[3] = GetTriangleArea(squareA[3], squareA[0], squareB[i]);

        double tmpArea = t[0] + t[1] + t[2] + t[3];
        if(tmpArea < areaA + 0.1f)
        {
            collisioned = true;
        }

        for(int j = 0; j<4; j++)
        {
            if(t[j] < 0.1f)
            {
                onSide = true;
                count++;
                break;
            }
        }
    }

    for(int i = 0; i< 4; i++)
    {
        double t[4];
        t[0] = GetTriangleArea(squareB[0], squareB[1], squareA[i]);
        t[1] = GetTriangleArea(squareB[1], squareB[2], squareA[i]);
        t[2] = GetTriangleArea(squareB[2], squareB[3], squareA[i]);
        t[3] = GetTriangleArea(squareB[3], squareB[0], squareA[i]);

        double tmpArea = t[0] + t[1] + t[2] + t[3];
        if(tmpArea < areaB + 0.1f)
        {
            collisioned = true;
        }

        for(int j = 0; j<4; j++)
        {

            if(t[j] < 0.1f)
            {
                onSide = true;
                count++;
                break;
            }
        }
    }

    if(collisioned)
    {

        if(onSide && count > 4)
        {
            cout << 1;
        }
        else if(onSide && count > 0)
        {
            cout << 2;
        }
        else if(count == 0)
        {
            cout << 4;
        }
        else
        {
            cout << 3;
        }
    }
    else
    {
        cout << 4;
    }


    return 0;
}