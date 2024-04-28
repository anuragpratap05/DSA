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

void pathSum(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> &sa)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr and root->right == nullptr)
    {
        if (targetSum - root->val == 0)
        {

            sa.push_back(root->val);
            ans.push_back(sa);
            sa.pop_back();
        }
        return;
    }
    sa.push_back(root->val);
    pathSum(root->left, targetSum - root->val, ans, sa);
    pathSum(root->right, targetSum - root->val, ans, sa);
    sa.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> sa;
    pathSum(root, targetSum, ans, sa);
    return ans;
}

int main()
{
    return 0;
}