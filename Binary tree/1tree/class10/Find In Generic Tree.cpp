#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
    this->val = val;
    }
};

class Node
{
public:
    int data = 0;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};
bool find(Node *node, int data)
{
    if (node->data == data)
    {
        return true;
    }
    bool res=false;
    for(Node* child:node->children)
    {
        res=res or find(child,data);
    }
    return res;
    
}
int main()
{
    return 0;
}