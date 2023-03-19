#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool SortByEndTime(const T& a, const T& b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int meetingCounts; cin >> meetingCounts;

    vector<pair<int, int>> meetings;

    for(int i = 0; i < meetingCounts; i++)
    {
        int startTime; cin >> startTime;
        int endTime; cin >> endTime;
        meetings.push_back(make_pair(startTime, endTime));
    }

    sort(meetings.begin(), meetings.end(), SortByEndTime<pair<int, int>>);

    int answer = 0;
    int endTime = 0;
    for(int i = 0; i < meetingCounts; i++)
    {
        if(endTime <= meetings[i].first)
        {
            endTime = meetings[i].second;
            answer++;
        }
    }

    cout << answer;

    return 0;
}