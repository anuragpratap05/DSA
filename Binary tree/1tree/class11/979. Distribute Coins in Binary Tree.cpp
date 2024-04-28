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
int distributeCoins2(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = distributeCoins2(root->left);
    ans += abs(left);
    int right = distributeCoins2(root->right);
    ans += abs(right);
    return left + right + (root->val - 1);
}
int distributeCoins(TreeNode *root)
{
    distributeCoins2(root);
    return ans;
}

int main()
{
    return 0;
}