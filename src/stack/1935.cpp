//
// Created by 승표손 on 2023/02/10.
//
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

    int operandsCounts; cin >> operandsCounts;

    string expression; cin >> expression;

    int operands[26];
    for(int i = 0; i< operandsCounts; i++)
    {
        cin >> operands[i];
    }

    stack<double> _stack;
    for(int i = 0; i < expression.length(); i++)
    {
        if(expression[i] >= 'A' && expression[i] <= 'Z')
        {
            int index = expression[i]-'A';
            _stack.push(operands[index]);
        }
        else
        {
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();

            double result = 0;
            if(expression[i] == '+')
            {
                result = a + b;
            }
            else if(expression[i] == '-')
            {
                result = a - b;
            }
            else if(expression[i] == '*')
            {
                result = a * b;
            }
            else if(expression[i] == '/')
            {
                result = a / b;
            }

            _stack.push(result);
        }
    }

    printf("%.2f",_stack.top());

    return 0;
}