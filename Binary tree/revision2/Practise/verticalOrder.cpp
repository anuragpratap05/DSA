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

int leftMin = 1e8;
int rightMax = -1e8;

void findWidth(TreeNode *root, int level)
{
    if (root == nullptr)
        return;

    leftMin = min(leftMin, level);
    rightMax = max(rightMax, level);
    findWidth(root->left, level - 1);
    findWidth(root->right, level + 1);
}

class qpair
{
public:
    int vl;
    TreeNode *par;
    qpair(TreeNode *par, int vl)
    {
        this->vl = vl;
        this->par = par;
    }
};

vector<vector<int>> verticalOrder(TreeNode *root)
{
    if (root == nullptr)
        return {{}};
    findWidth(root, 0);
    int size = (rightMax - leftMin) + 1;

    vector<vector<int>> ans(size, vector<int>());
    queue<qpair> q;
    q.push(qpair(root, abs(leftMin)));

    while (!q.empty())
    {
        qpair info = q.front();
        q.pop();
        TreeNode *par = info.par;
        int vl = info.vl;
        ans[vl].push_back(par->val);
        if (par->left)
            q.push(qpair(par->left, vl - 1));
        if (par->right)
            q.push(qpair(par->right, vl + 1));
    }
    return ans;
}

int main()
{
    return 0;
}