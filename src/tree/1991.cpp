#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int tree[26][2];


void PreorderTraversal(int root)

{
    if(root >= 0)
    {
        cout << (char)(root + 'A');
        PreorderTraversal(tree[root][0]);
        PreorderTraversal(tree[root][1]);
    }
}

void InorderTraversal(int root)

{
    if(root >= 0)
    {
        InorderTraversal(tree[root][0]);
        cout << (char)(root + 'A');
        InorderTraversal(tree[root][1]);
    }
}

void PostorderTraversal(int root)

{
    if(root >= 0)
    {
        PostorderTraversal(tree[root][0]);
        PostorderTraversal(tree[root][1]);
        cout << (char)(root + 'A');
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int nodeCounts; cin >> nodeCounts;

    for(int i =0; i< nodeCounts; i++)
    {
        char parentNode; cin >> parentNode;
        int parentIndex = parentNode - 'A';
        for(int j = 0; j< 2; j++)
        {
            char childNode; cin >> childNode;
            int childIndex = childNode - 'A';
            if( childIndex >= 0 && childIndex <= 25)
            {
                tree[parentIndex][j] = childIndex;
            }
            else
            {
                tree[parentIndex][j] = -1;
            }

        }
    }

    PreorderTraversal(0);
    cout << '\n';
    InorderTraversal(0);
    cout << '\n';
    PostorderTraversal(0);
    cout << '\n';


    return 0;
}