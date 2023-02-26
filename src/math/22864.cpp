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

    int workingFatigue; cin >> workingFatigue;
    int workingAmount; cin >> workingAmount;
    int restFatigue; cin >> restFatigue;
    int maxFatigue; cin >> maxFatigue;

    int fatigue = 0;
    int working = 0;
    for(int i = 0; i < 24; i++)
    {
        if(fatigue + workingFatigue <= maxFatigue)
        {
            //have to work
            working += workingAmount;
            fatigue += workingFatigue;
        }
        else
        {
            //have to rest
            if(fatigue - restFatigue < 0)
            {
                fatigue = 0;
            }
            else
            {
                fatigue -= restFatigue;
            }
        }
    }

    cout << working;

    return 0;
}