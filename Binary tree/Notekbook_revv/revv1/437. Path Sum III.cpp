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

int ans = 0;
void pathSumHelp(TreeNode *root, int targetSum, long long curSum, unordered_map<long long, int> &mp)
{
    if (root == nullptr)
        return;
    curSum += root->val;
    if(mp.find(curSum-targetSum)!=mp.end())
        ans += mp[curSum - targetSum];
    mp[curSum]++;
    pathSumHelp(root->left, targetSum, curSum, mp);
    pathSumHelp(root->right, targetSum, curSum, mp);
    if(--mp[curSum]==0)
        mp.erase(curSum);
}

int pathSum(TreeNode *root, int targetSum)
{
    if(root==nullptr)
        return 0;
    unordered_map<long long, int> mp;
    mp[0] = 1;
    pathSumHelp(root, targetSum, 0, mp);
    return ans;
}

int main()
{
    return 0;
}