#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<int> people;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;
    people.reserve(counts);

    for(int i = 0; i < counts; i++)
    {
        int num; cin >> num;
        people.push_back(num);
    }

    sort(people.begin(), people.end(), greater<int>());

    long long result = 0;
    for(int i =0; i< counts; i++)
    {
        if(people[i] < i)
        {
            break;
        }

        result += people[i] - i;
    }

    cout << result;

    return 0;
}