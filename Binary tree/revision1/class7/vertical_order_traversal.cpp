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
vector<int> vec(2, 0);

void shadow(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return;
    }
    vec[0] = min(vec[0], x);
    vec[1] = max(vec[1], x);
    shadow(root->left, x - 1);
    shadow(root->right, x + 1);
}

vector<vector<int>> vertical_order_traversal(TreeNode *root, int k,int size)
{
    vector<vector<int>> vec(size, vector<int>());

    queue<pair<TreeNode *, int>> q;

    q.push({root, k});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *rn = p.first;
        k = p.second;
        vec[k].push_back(rn->val);
        if(rn->left!=nullptr)
        {
            q.push({rn->left, k - 1});
        }
        if (rn->right != nullptr)
        {
            q.push({rn->right, k + 1});
        }
    }
    return vec;
}

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    shadow(root, 0);
    int size = (vec[1] - vec[0]) + 1;

    vector<vector<int>>ans= vertical_order_traversal(root, abs(vec[0]), size);
    return ans;
}

int main()
{
    return 0;
}