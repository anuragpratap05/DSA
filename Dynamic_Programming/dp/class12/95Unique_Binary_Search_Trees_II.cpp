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

void display(vector<TreeNode *> &vec)
{
    for (TreeNode *root : vec)
    {
        if (root == nullptr)
            cout << "null ";
        else
            cout << root->val << " ";
    }
}

vector<TreeNode *> generateTreesMemo(int n, int s, int e, vector<vector<vector<TreeNode *>>> &dp)
{
    if (s >= e)
    {
        if (s == e)
        {
            TreeNode *base = new TreeNode(s);
            return dp[s][e] = {base};
        }
        else
        {
            return dp[s][e] = {nullptr};
        }
    }
    if (dp[s][e].size() > 0)
        return dp[s][e];

    vector<TreeNode *> ans;
    for (int cut = s; cut <= e; cut++)
    {
        vector<TreeNode *> left = generateTreesMemo(n, s, cut - 1, dp);
        vector<TreeNode *> right = generateTreesMemo(n, cut + 1, e, dp);
        for (TreeNode *lSubTree : left)
        {
            for (TreeNode *rSubTree : right)
            {
                TreeNode *root = new TreeNode(cut);
                root->left = lSubTree;
                root->right = rSubTree;
                ans.push_back(root);
            }
        }
    }
    return dp[s][e] = ans;
}

vector<TreeNode *> generateTrees(int n)
{
    vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>()));
    return generateTreesMemo(n, 1, n, dp);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    vector<vector<vector<int>>> dp(1, vector<vector<int>>(1, vector<int>()));
    cout << "size--> " << dp[0][0].size() << endl;
    dp[0][0](vec);
    cout << "size--> " << dp[0][0].size() << endl;

    return 0;
}