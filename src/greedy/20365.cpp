#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int counts;
string problems;

int GetCountsBasedByCharacter(char target)
{
    int answer = 0;
    for(int i = 0; i< counts; i++) {
        bool findTarget = false;
        while (problems[i] == target)
        {
            findTarget = true;
            i++;
        }

        if (findTarget)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> counts;
    cin >> problems;

    int answerB = 1 + GetCountsBasedByCharacter('B');
    int answerR = 1 + GetCountsBasedByCharacter('R');

    cout << min(answerB, answerR);

    return 0;
}