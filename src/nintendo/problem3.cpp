#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x;
    double y;
    double z;
};

struct Vector{
    double x;
    double y;
    double z;
};

Point A;
Point B;

int n;

Vector line;
double lineSize;

void InputPoint(Point& a)
{
    cin >> a.x >> a.y >> a.z;
}

Vector CrossProduct(Vector a, Vector b) {
    Vector cp;
    cp.x = a.y * b.z - a.z * b.y;
    cp.y = -(a.x * b.z - a.z * b.x);
    cp.z = a.x * b.y - a.y * b.x;

    return cp;
}

double CalculateSize(Vector a)
{
    return sqrt((a.x)*(a.x) + (a.y)*(a.y) + (a.z)*(a.z));
}

double CalculateScore(Point x)
{
    Vector ax;
    ax.x= x.x - A.x;
    ax.y= x.y - A.y;
    ax.z= x.z - A.z;

    Vector cp = CrossProduct(ax, line);

    return CalculateSize(cp) / lineSize;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    InputPoint(A);
    InputPoint(B);

    cin >> n;

    line.x = A.x - B.x;
    line.y = A.y - B.y;
    line.z = A.z - B.z;
    lineSize = CalculateSize(line);

    double minRedScore = DBL_MAX;
    double minGreenScore = DBL_MAX;
    double minBlueScore = DBL_MAX;


    for(int i = 0; i < n; i++)
    {
        Point pointRed;
        Point pointGreen;
        Point pointBlue;

        InputPoint(pointRed);
        InputPoint(pointGreen);
        InputPoint(pointBlue);

        double scoreRed =  CalculateScore(pointRed);
        double scoreGreen =  CalculateScore(pointGreen);
        double scoreBlue =  CalculateScore(pointBlue);

        if(minRedScore > scoreRed)
            minRedScore = scoreRed;

        if(minGreenScore > scoreGreen)
            minGreenScore = scoreGreen;

        if(minBlueScore > scoreBlue)
            minBlueScore = scoreBlue;
    }

    double minScore = min({minRedScore, minGreenScore, minBlueScore});
    if(minScore == minRedScore)
    {
        cout << 'R' << '\n';
    }
    else if(minScore == minGreenScore)
    {
        cout << 'G' << '\n';
    }
    else if(minScore == minBlueScore)
    {
        cout << 'B' << '\n';
    }

    cout << fixed;
    cout.precision(9);

    cout << minScore;

    return 0;
}