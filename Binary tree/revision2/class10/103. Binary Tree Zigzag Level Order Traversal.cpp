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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    stack<TreeNode *> st;
    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int>> ans;
    int level = 0;
    while (!q.empty())
    {
        if (ans.size() == level)
            ans.push_back({});
        int size = q.size();
        while (size--)
        {
            TreeNode *node = q.front();
            q.pop();
            ans[level].push_back(node->val);
            if (level % 2 == 0)
            {
                if (node->left)
                    st.push(node->left);
                if (node->right)
                    st.push(node->right);
            }
            else
            {
                if (node->right)
                    st.push(node->right);
                if (node->left)
                    st.push(node->left);
            }
        }
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        level++;
    }
    return ans;
}

vector<vector<int>> zigzagLevelOrder2(TreeNode *root)
{
}

int main()
{
    return 0;
}