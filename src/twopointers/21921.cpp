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

    int num; cin >> num;
    int during; cin >> during;

    vector<int> arr(num);

    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    long long sum = 0;
    for(int i = 0; i < during; i++)
    {
        sum += arr[i];
    }

    long long max = sum;
    int count = 1;
    for(int i = 1; i<= num - during; i++)
    {
        sum -= arr[i-1];
        sum += arr[i-1+during];
        if(max < sum)
        {
            max = sum;
            count = 1;
        }
        else if(max == sum)
        {
            count++;
        }
    }

    if(max == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << max << '\n' << count;
    }

    return 0;
}