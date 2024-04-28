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

class rootInfo
{
public:
    int hl;
    int vl;
    TreeNode *root;
    rootInfo(int hl, int vl, TreeNode *root)
    {
        this->hl = hl;
        this->vl = vl;
        this->root = root;
    }
};

class comp
{
public:
    bool operator()(rootInfo &a, rootInfo &b)
    {
        // if (a.hl == b.hl and a.vl == b.vl) --> wrong
        //     return b.root->val < a.root->val;
        // return b.hl < a.hl;

        if (a.hl == b.hl)
            return b.root->val < a.root->val;
        return b.hl < a.hl;
    }
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    findBoundries(root, 0);
    int width = (rightMax - leftMin) + 1;
    vector<vector<int>> ans(width, vector<int>());
    priority_queue<rootInfo, vector<rootInfo>, comp> pq;

    pq.push(rootInfo(0, abs(leftMin), root));

    while (!pq.empty())
    {
        rootInfo curInfo = pq.top();
        pq.pop();

        int curHl = curInfo.hl;
        int curVl = curInfo.vl;
        TreeNode *curRoot = curInfo.root;

        ans[curVl].push_back(curRoot->val);

        if (curRoot->left)
            pq.push(rootInfo(curHl + 1, curVl - 1, curRoot->left));

        if (curRoot->right)
            pq.push(rootInfo(curHl + 1, curVl + 1, curRoot->right));
    }
    return ans;
}

int main()
{
    return 0;
}