#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<long long> numbers;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int counts; cin >> counts;
    numbers.reserve(counts);

    for(int i =0; i< counts; i++)
    {
        long long num; cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());


    long long max = 0;
    if(counts % 2 == 0)
    {
        for(int i = 0; i < counts/2; i++)
        {
            long long sum = numbers[i] + numbers[counts - 1 - i];
            if(max < sum)
            {
                max = sum;
            }
        }
    }
    else
    {
        for(int i = 0; i < counts/2; i++)
        {
            long long sum = numbers[i] + numbers[counts - 2 - i];
            if(max < sum)
            {
                max = sum;
            }
        }

        if(max < numbers[counts - 1])
        {
            max = numbers[counts - 1];
        }
    }

    cout << max;

    return 0;
}