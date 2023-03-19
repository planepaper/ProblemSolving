#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int startNumber; cin >> startNumber;
    int endNumber; cin >> endNumber;

    int answer = 1;
    while(endNumber != startNumber && endNumber != 0)
    {
        if(endNumber % 10 == 1)
        {
            endNumber /= 10;
        }
        else if(endNumber % 2 == 0)
        {
            endNumber /= 2;
        }
        else
        {
            answer = -1;
            break;
        }

        answer++;
    }

    if(endNumber == 0)
    {
        answer = -1;
    }
    cout << answer;

    return 0;
}