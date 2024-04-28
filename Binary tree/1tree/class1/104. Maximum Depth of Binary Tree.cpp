#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int val=0;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;
    TreeNode(int val)
    {
        this->val=val;
    }
};

int maxDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return max(a,b)+ 1;
}

int main()
{
    return 0;
}