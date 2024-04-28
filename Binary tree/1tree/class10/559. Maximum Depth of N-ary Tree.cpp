#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int val = 0;
    vector<Node*> children;
};

int maxDepth(Node *root)
{
    int depth=0;
    for(Node* child:root->children)
    {
        depth=max(depth,maxDepth(child));
    }
    return depth+1;
}

int main()
{
    return 0;
}