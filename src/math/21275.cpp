#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int FindMaxBase(string a)
{
    int max = 0;
    for(int i = 0; i < a.length(); i++)
    {
        int base;
        if(isdigit(a[i]))
        {
            base = a[i] - '0';
        }
        else
        {
            base = a[i] - 'a' + 10;
        }

        if(max < base) max = base;
    }

    return max + 1;
}

int CalculateNumWithBase(string a, int base)
{
    long long sum = 0;
    long long multiple = 1;
    for(int i = a.length() - 1; i >= 0; i--)
    {
        int num;
        if(isdigit(a[i]))
        {
            num = a[i] - '0';
        }
        else
        {
            num = a[i] - 'a' + 10;
        }

        long long amount = num * multiple;
        sum += amount;

        if(amount < 0 || sum < 0) return -1;

        multiple *= base;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    string a; cin >> a;
    string b; cin >> b;

    //find max letter on each string
    int aMaxBase = FindMaxBase(a);
    int bMaxBase = FindMaxBase(b);

    //store expecting results on unordered_set
    unordered_map<long long, int> firstExpect;
    for(int i = aMaxBase; i <= 36; i++)
    {
        long long aResult = CalculateNumWithBase(a, i);

        if(aResult < 0) break;

        firstExpect.emplace(aResult, i);
    }


    //matching with b result and store on result vector
    vector<tuple<long long, int, int>> results;
    for(int i = bMaxBase; i <= 36; i++)
    {
        long long bResult = CalculateNumWithBase(b,i);

        if(bResult < 0) break;

        if(firstExpect.find(bResult) != firstExpect.end()
            && firstExpect[bResult] != i)
        {
            results.push_back(make_tuple(bResult, firstExpect[bResult], i));
        }
    }

    if(results.size() > 1)
    {
        cout << "Multiple";
    }
    else if(results.size() == 1)
    {
        cout << get<0>(results[0]) << ' '
        << get<1>(results[0]) << ' '
        << get<2>(results[0]);
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}