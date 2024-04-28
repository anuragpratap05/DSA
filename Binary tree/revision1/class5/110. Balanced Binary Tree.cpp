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

class pair_{
public:
    bool isbalanced;
    int ht;
};

pair_ isBalanced_help(TreeNode *root)
{
    if (root == nullptr)
    {
        pair_ base;
        base.isbalanced = true;
        base.ht = -1;
        return base;
    }
    pair_ left = isBalanced_help(root->left);
    if(!left.isbalanced)
    {
        return left;
    }
    pair_ right = isBalanced_help(root->right);
    pair_ myans;
    if(left.isbalanced and right.isbalanced and abs(left.ht-right.ht)<=1)
    {
        myans.isbalanced=true;
        myans.ht=max(left.ht,right.ht)+1;
    }
    else
    {
        myans.isbalanced=false;
    }
    return myans;


}
    

bool isBalanced(TreeNode *root)
{
    if(root==nullptr)
    {
        return true;
    }
    return isBalanced_help(root).isbalanced;
}

int main()
{
    return 0;
}