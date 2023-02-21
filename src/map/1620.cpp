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

    unordered_map<int, string> pokeDexByNum;
    unordered_map<string, int> pokeDexByName;

    int dexCounts; cin >> dexCounts;
    int problemCounts; cin >> problemCounts;

    for(int i = 1;i<= dexCounts; i++)
    {
        string pokemonName; cin >> pokemonName;
        pokeDexByNum.emplace(i, pokemonName);
        pokeDexByName.emplace(pokemonName, i);
    }

    for(int i = 0; i< problemCounts; i++)
    {
        string quiz; cin >> quiz;

        if(isdigit(quiz[0]))
        {
            int queryNum = stoi(quiz);
            cout << pokeDexByNum[queryNum] << '\n';
        }
        else
        {
            cout << pokeDexByName[quiz] << '\n';
        }
    }

    return 0;
}