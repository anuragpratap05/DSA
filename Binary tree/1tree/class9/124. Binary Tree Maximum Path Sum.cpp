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

class pair_
{
    public:
    int allover_max;
    int ht;
};
// using return type
pair_ maxPathSum_help(TreeNode *root)
{
    if (root == nullptr)
    {
        pair_ base;
        base.allover_max = -10000;
        base.ht = 0;
        return base;
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        pair_ base;
        base.allover_max = root->val;
        base.ht = root->val;
        return base;
    }
    pair_ left = maxPathSum_help(root->left);
    pair_ right = maxPathSum_help(root->right);

    pair_ mypair;
    // cout<<"before setting";
    int r_to_n = max(left.ht, right.ht) + root->val;
    // cout<<left.allover_max<<"  "<<right.allover_max<<endl;
    mypair.allover_max = max(left.allover_max, right.allover_max);
    mypair.allover_max = max(mypair.allover_max, r_to_n);
    mypair.allover_max = max(mypair.allover_max, root->val);
    mypair.allover_max = max(mypair.allover_max, left.ht + root->val + right.ht);

    mypair.ht = max(r_to_n, root->val);
    // cout<<left.allover_max<<"  "<<right.allover_max<<endl;
    //  cout<<"after setting";
    //  cout<<left.allover_max<<"  "<<right.allover_max<<endl;
    return mypair;
}

int maxPathSum(TreeNode *root)
{
    return maxPathSum_help(root).allover_max;
}
// using global/static
int allover_max = -10000;
int maxPathSum2(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = maxPathSum2(root->left);
    int right = maxPathSum2(root->right);

    int r_to_n = max(left, right) + root->val;

    allover_max = max(allover_max, r_to_n);
    allover_max = max(allover_max, root->val);
    allover_max = max(allover_max, left + right + root->val);

    return max(r_to_n, root->val);
}
int maxPathSum(TreeNode *root)
{
    maxPathSum2(root);
    return allover_max;
}

int main()
{
    return 0;
}