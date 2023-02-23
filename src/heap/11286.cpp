#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

class Compare
{public:
    bool operator()(const int& below, const int& above)
    {
        int absBelow, absAbove;
        below < 0 ? absBelow = -below : absBelow = below;
        above < 0 ? absAbove = -above : absAbove = above;

        if(absBelow > absAbove)
        {
            return true;
        }
        else if(absBelow < absAbove)
        {
            return false;
        }
        else
        {
            if(above < 0 && below > 0)
                return true;
        }
        return false;
    }
};  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    priority_queue<int, vector<int>, Compare> heap;

    int opCounts; cin >> opCounts;

    for(int i = 0; i <opCounts; i++)
    {
        int op; cin >> op;
        if(op == 0)
        {
            if(heap.empty())
            {
                cout << 0 << '\n';
            }
            else
            {

                cout << heap.top() << '\n';
                heap.pop();
            }
        }
        else
        {
            heap.push(op);
        }
    }

    return 0;
}