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

vector<int> levelOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        ans.push_back(q.front()->val);
        while (size--)
        {
            TreeNode *curRoot = q.front();
            q.pop();
            if (curRoot->right)
                q.push(curRoot->right);
            if (curRoot->left)
                q.push(curRoot->left);
        }
    }
    return ans;
}

vector<int> rightSideView(TreeNode *root)
{
    return levelOrder(root);
}

int main()
{
    return 0;
}