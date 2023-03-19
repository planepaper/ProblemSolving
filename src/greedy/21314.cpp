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

    string minkyumNum; cin >> minkyumNum;

    string max;
    int mCounts = 0;
    for(int i = 0; i < minkyumNum.length(); i++)
    {
        if(minkyumNum[i] == 'M')
        {
            mCounts++;
        }
        else
        {
            max += '5';
            for(int j = 0; j < mCounts; j++)
            {
                max += '0';
            }
            mCounts = 0;
        }
    }
    if(mCounts != 0)
    {
        for(int j = 0; j < mCounts; j++)
        {
            max += '1';
        }
    }


    string min;
    mCounts = 0;
    for(int i = 0; i < minkyumNum.length(); i++)
    {
        if(minkyumNum[i] == 'M')
        {
            mCounts++;
        }
        else
        {
            if(mCounts != 0)
            {
                min += '1';
                for(int j = 1; j < mCounts; j++)
                {
                    min += '0';
                }
            }
            min += '5';

            mCounts = 0;
        }
    }
    if(mCounts != 0)
    {
        min += '1';
        for(int j = 1; j < mCounts; j++)
        {
            min += '0';
        }
    }

    cout << max << '\n';
    cout << min;

    return 0;
}