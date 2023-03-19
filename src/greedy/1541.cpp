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


    vector<int> operands;
    vector<char> operators;
    operators.push_back(' ');

    string expression; cin >> expression;

    for(int i = 0; i < expression.length(); i++)
    {
        if(isdigit(expression[i]))
        {
            string num;
            while(isdigit(expression[i]))
            {
                num += expression[i];
                i++;
            }
            i--;

            operands.push_back(stoi(num));
        }
        else
        {
            operators.push_back(expression[i]);
        }
    }

    long long answer = operands[0];

    int firstMinusIndex = operators.size();
    for(int i = 1; i< operators.size(); i++)
    {
        if(operators[i] == '-')
        {
            firstMinusIndex = i;
            break;
        }
        else
        {
            answer += operands[i];
        }
    }

    int cumulative = 0;
    for(int i = firstMinusIndex; i< operators.size(); i++)
    {
        if(operators[i] == '-')
        {
            answer -= cumulative;
            cumulative = operands[i];
        }
        else
        {
            cumulative += operands[i];
        }
    }

    if(cumulative != 0)
    {
        answer -= cumulative;
    }

    cout << answer;

    return 0;
}