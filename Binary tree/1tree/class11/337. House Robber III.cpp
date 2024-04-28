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
vector<int> rob_help(TreeNode *root)
{
    if(root==nullptr)
    {
        return {0,0};
    }
    vector<int>left=rob_help(root->left);
    vector<int>right=rob_help(root->right);

    vector<int> ans(2,0);
    ans[0]=left[1]+root->val+right[1];
    ans[1]=max(left[0],left[1])+max(right[0],right[1]);
    return ans;
}
int rob(TreeNode *root)
{
    vector<int>ans=rob_help(root);
    return max(ans[0],ans[1]);
}

int main()
{
    return 0;
}