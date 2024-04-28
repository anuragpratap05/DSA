#include <bits/stdc++.h>
using namespace std;

// class 11 me ek ques rh gya h apple wala last ques hai dekh lena kbhi...
//687
//1339
// y dono H.W hai

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
int distributeCoins_help(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = distributeCoins_help(root->left);
    int right = distributeCoins_help(root->right);
    ans += abs(left);
    ans += abs(right);
    return ((left + right) + (root->val - 1));
}

int distributeCoins(TreeNode *root)
{
    distributeCoins_help(root);
    return ans;
}

int main()
{
    return 0;
}