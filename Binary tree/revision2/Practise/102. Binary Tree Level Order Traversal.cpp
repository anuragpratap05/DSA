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
    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int>> ans;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (ans.size() == level)
            ans.push_back({});
        while (size--)
        {
            TreeNode *curNode = q.front();
            q.pop();
            ans[level].push_back(curNode->val);
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
        }
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}