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

bool hasPathSum2(TreeNode *root, int targetSum, int sum, vector<vector<int>>& ans,vector<int>& sa)
{
    if (root == nullptr)
    {
        return false;
    }

    sum += root->val;
    sa.push_back(root->val);
    bool left = hasPathSum2(root->left, targetSum, sum,ans,sa);
    
    bool right = hasPathSum2(root->right, targetSum, sum,ans,sa);
    
    //cout << root->val << "  " << sum << endl;
    if (sum == targetSum  and (root->left == nullptr and root->right == nullptr))
    {
        ans.push_back(sa);
        sa.pop_back();
        return true;
    }
    else
    {
        sa.pop_back();
        return false;
    }
        
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int>sa;
    hasPathSum2(root,targetSum,0,ans,sa);
    return ans;
}

int main()
{
    return 0;
}