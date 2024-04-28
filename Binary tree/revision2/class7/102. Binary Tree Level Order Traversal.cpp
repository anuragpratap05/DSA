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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    int level = 0;
    while (!q.empty())
    { 
        int size = q.size();
        if (ans.size() == level)
            ans.push_back({});

        while (size--)
        {
            TreeNode *curRoot = q.front();
            q.pop();
            ans[level].push_back(curRoot->val);
            if (curRoot->left)
                q.push(curRoot->left);
            if (curRoot->right)
                q.push(curRoot->right);
        }
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}