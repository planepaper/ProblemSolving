//
// Created by seungpyo on 2023-02-18.
//
#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int balloonJumpingNum[1001];
bool balloonsFlag[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int balloonCounts; cin >> balloonCounts;

    for(int i = 1; i <= balloonCounts; i++)
    {
        cin >> balloonJumpingNum[i];
        balloonsFlag[i] = true;
    }

    int index = 1;
    for(int i = 1; i < balloonCounts; i++)
    {
        //pop balloon
        cout << index << ' ';
        balloonsFlag[index] = false;

        //confirm balloon
        int jumpingNum = balloonJumpingNum[index];


        int trueCounts = 0;
        if(jumpingNum> 0)
        {
            while(trueCounts != jumpingNum)
            {
                index++;
                if(index > balloonCounts)
                {
                    index = 1;
                }

                if(balloonsFlag[index])
                {
                    trueCounts++;
                }
            }
        }
        else
        {
            while(trueCounts != jumpingNum)
            {
                index--;
                if(index < 1)
                {
                    index = balloonCounts;
                }

                if(balloonsFlag[index])
                {
                    trueCounts--;
                }
            }
        }
    }
    cout << index << ' ';

}