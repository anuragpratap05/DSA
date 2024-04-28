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

pair<int,bool> isbalanced(TreeNode* root)
{
    if(root==nullptr)
    {
        return {-1,true};
    }

    pair<int,bool> left=isbalanced(root->left);
    if(!left.second)
    {
        return {0,false};
    }
    pair<int,bool> right=isbalanced(root->right);
    if (!right.second)
    {
        return {0, false};
    }

    int h= max(left.first,right.first)+1;
    bool res= (abs(left.first-right.first)>1?false:true);

    return {h,res};

}

bool isBalanced(TreeNode *root)
{
    return isbalanced(root).second;
}

int main()
{
    return 0;
}