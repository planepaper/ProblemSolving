#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    unordered_set<string> s;

    int stringCounts; cin >> stringCounts;
    int quizCounts; cin >> quizCounts;

    for(int i =0;i< stringCounts; i++)
    {
        string str; cin >> str;
        s.insert(str);
    }

    int answer = 0;
    for(int i=0; i<quizCounts;i++)
    {
        string str; cin >> str;
        if(s.find(str) != s.end())
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}