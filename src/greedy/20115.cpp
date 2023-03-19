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

    int counts; cin >> counts;

    int max = 0;
    double answer = 0;

    for(int i = 0; i< counts; i++)
    {
        int num; cin >> num;
        answer += num;

        if(max < num)
        {
            max = num;
        }
    }

    answer -= max;
    answer = max + answer/2;

    cout << answer;

    return 0;
}