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

class p{
public:
    int rob = 0;
    int not_rob = 0;
};


p rob_help(TreeNode *root)
{
    if(root==nullptr)
    {
        p x;
        return x;
    }

    p left = rob_help(root->left);
    p right = rob_help(root->right);

    p myp;
    myp.rob = (left.not_rob + right.not_rob) + root->val;
    myp.not_rob = max(left.not_rob, left.rob) + max(right.not_rob, right.rob);

    return myp;
}

int rob(TreeNode *root)
{
    p ans= rob_help(root);
    return max(ans.rob, ans.not_rob);
}

int main()
{
    return 0;
}