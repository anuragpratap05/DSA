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
void level_order(TreeNode *root, vector<int> &sa)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        // cout << "level:" << level << "-->";
        // sa.clear();
        sa.push_back(q.back()->val);
        while (size--)
        {
            TreeNode *rn = q.front();
            q.pop();
            // << rn->val;

            if (rn->left != nullptr)
            {
                q.push(rn->left);
            }
            if (rn->right != nullptr)
            {
                q.push(rn->right);
            }
        }
        // ans.push_back(sa);
        level++;
    }
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int>ans;
    level_order(root,ans);
    return ans;
}

int main()
{
    return 0;
}