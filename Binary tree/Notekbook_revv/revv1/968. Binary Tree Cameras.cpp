#include <bits/stdc++.h>
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

struct NodeInfo
{
    int self = -11, lc = -1, rc = -1;
};
int camera = 0;

NodeInfo minCameraCoverHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        NodeInfo base;
        return base;
    }

    NodeInfo left = minCameraCoverHelp(root->left);
    NodeInfo right = minCameraCoverHelp(root->right);
    NodeInfo curNode;
    curNode.lc = left.self;
    curNode.rc = right.self;

    if ((left.self == 0 and left.lc != 1 and left.rc != 1) or (right.self == 0 and right.lc != 1 and right.rc != 1))
    {
        camera++;
        curNode.self = 1;
    }
    else
        curNode.self = 0;
    return curNode;
}

int minCameraCover(TreeNode *root)
{
    NodeInfo rootInfo = minCameraCoverHelp(root);
    if (rootInfo.self == 0 and rootInfo.lc != 1 and rootInfo.rc != 1)
        camera++;
    return camera;
}

int main()
{
    return 0;
}