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

int leftMin = 0, rightMax = 0;

void getBoundries(TreeNode *root, int curVerLevel)
{
    if (root == nullptr)
        return;
    leftMin = min(leftMin, curVerLevel);
    rightMax = max(rightMax, curVerLevel);
    getBoundries(root->left, curVerLevel - 1);
    getBoundries(root->right, curVerLevel + 1);
    return;
}

class RootInfo
{
public:
    TreeNode *root = nullptr;
    int hl, vl;
    RootInfo(TreeNode *root, int hl, int vl)
    {
        this->root = root;
        this->hl = hl;
        this->vl = vl;
    }
};

class comp
{
public:
    bool operator()(RootInfo &a, RootInfo &b)
    {
        if (a.hl == b.hl)
            return b.root->val < a.root->val;
        return b.hl < a.hl;
    }
};

vector<vector<int>> verticalOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    getBoundries(root, 0);
    int n = (rightMax - leftMin) + 1;
    vector<vector<int>> ans(n, vector<int>());

    // queue<pair<TreeNode *, int>> q;
    priority_queue<RootInfo, vector<RootInfo>, comp> pq;
    pq.push(RootInfo(root, 0, abs(leftMin)));

    while (!pq.empty())
    {
        RootInfo curNode = pq.top();
        pq.pop();
        TreeNode *node = curNode.root;
        int verLevel = curNode.vl;
        int horLevel = curNode.hl;

        ans[verLevel].push_back(node->val);
        if (node->left)
            pq.push(RootInfo(node->left, horLevel + 1, verLevel - 1));
        if (node->right)
            pq.push(RootInfo(node->right, horLevel + 1, verLevel + 1));
    }

    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    return verticalOrder(root);
}

int main()
{
    return 0;
}