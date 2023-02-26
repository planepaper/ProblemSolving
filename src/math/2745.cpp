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


    string num; cin >> num;
    int howMuch; cin >> howMuch;

    int answer = 0;
    for(int i = num.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if( '0' <= num[i] && '9' >= num [i])
        {
            answer += pow(howMuch, j) * (num[i] - '0');
        }
        else
        {
            answer += pow(howMuch, j) * (num [i] - 'A' + 10);
        }
    }

    cout << answer;

    return 0;
}