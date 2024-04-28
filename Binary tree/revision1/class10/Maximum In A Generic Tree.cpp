#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

int size(Node *node)
{
    int ans = INT_MIN;
    for(auto child:node->children)
    {
        ans = max(ans, size(child));
    }
    return max(ans, node->data);
}

int main()
{
    return 0;
}