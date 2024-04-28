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
bool hasPathSum_(TreeNode *root, int targetSum, int ssf, vector<vector<int>>& ans,vector<int>& sa)
{
    if (root == nullptr)
    {

        return false;
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        if (targetSum == ssf + root->val)
        {
            sa.push_back(root->val);
            ans.push_back(sa);
            sa.pop_back();
            return true;
        }
        return false;
    }

    sa.push_back(root->val);
    bool l = hasPathSum_(root->left, targetSum, ssf + root->val,ans,sa);

    bool r = hasPathSum_(root->right, targetSum, ssf + root->val, ans, sa);
    sa.pop_back();

    return false;
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> sa;
    hasPathSum_(root, targetSum, 0, ans, sa);
    return ans;
}

int main()
{
    return 0;
}