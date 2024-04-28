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
int height(Node *node)
{
    int ht=-1;
    for(Node* child:node->children)
    {
        ht=max(ht,height(child));
    }
    return ht+1;
}

int main()
{
    return 0;
}