#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

int height(Node *node)
{
    int ht = -1;
    for(auto child:node->children)
    {
        ht = max(ht, height(child));
    }
    return ht + 1;
}

int main()
{
    return 0;
}