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

bool find(Node *node, int data, vector<int> &ans)
{

    if (node->data == data)
    {
        ans.push_back(node->data);
        return true;
    }
    bool res = false;
    for (Node *child : node->children)
    {
        res = find(child, data, ans);
        if (res)
        {
            ans.push_back(node->data);
            return true;
        }
    }

    return false;
}
vector<int> nodeToRootPath(Node *node, int data)
{
    vector<int>ans;
    find(node,data,ans);
    return ans;

    // Write your code here
}

int main()
{
    return 0;
}