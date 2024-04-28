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

int ans = 0;
void pathSum(TreeNode *root, int targetSum, int curSum, unordered_map<int, int> &mp)
{
    if (root == nullptr)
        return;
    curSum += root->val;
    if (mp.find(curSum - targetSum) != mp.end())
    {
        ans += mp[curSum - targetSum];
    }
    mp[curSum]++;

    pathSum(root->left, targetSum, curSum, mp);
    pathSum(root->right, targetSum, curSum, mp);
    if (--mp[curSum] == 0)
        mp.erase(curSum);
}

int pathSum(TreeNode *root, int targetSum)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    pathSum(root, targetSum, 0, mp);
    return ans;
}

int main()
{
    return 0;
}