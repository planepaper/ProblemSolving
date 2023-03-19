#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int edges[100000];
int priceOfCities[100000];

vector<int> visitingCities;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int cityCounts; cin >> cityCounts;

    for(int i = 0; i < cityCounts -1; i++)
    {
        cin >> edges[i];
    }

    for(int i = 0; i < cityCounts; i++)
    {
        cin >> priceOfCities[i];
    }

    int minPrice = 1000000000;
    long long totalPrice = 0;

    for(int i = 0; i< cityCounts - 1; i++)
    {
        if(priceOfCities[i] < minPrice)
        {
            minPrice = priceOfCities[i];
        }

        totalPrice += (long long)minPrice * edges[i];
    }

    cout << totalPrice;

    return 0;
}