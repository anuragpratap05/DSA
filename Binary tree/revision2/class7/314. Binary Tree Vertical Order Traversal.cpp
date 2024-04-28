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

int leftMin = 1e9;
int rightMax = -1e9;

void findBoundries(TreeNode *root, int level)
{
    if (root == nullptr)
        return;
    leftMin = min(leftMin, level);
    rightMax = max(rightMax, level);
    findBoundries(root->left, level - 1);
    findBoundries(root->right, level + 1);
}

class qPair
{
public:
    TreeNode *par;
    int verLevel;
    qPair(TreeNode *par, int verLevel)
    {
        this->par = par;
        this->verLevel = verLevel;
    }
};

vector<vector<int>> verticalOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    findBoundries(root, 0);
    int width = (rightMax - leftMin) + 1;
    vector<vector<int>> ans(width, vector<int>());
    queue<qPair> q;

    q.push(qPair(root, abs(leftMin)));

    while (!q.empty())
    {
        qPair rootPair = q.front();
        q.pop();
        TreeNode *curRoot = rootPair.par;
        int curVerLevel = rootPair.verLevel;
        ans[curVerLevel].push_back(curRoot->val);
        if (curRoot->left)
            q.push(qPair(curRoot->left, curVerLevel - 1));
        if (curRoot->right)
            q.push(qPair(curRoot->right, curVerLevel + 1));
    }
    return ans;
}

int main()
{
    return 0;
}