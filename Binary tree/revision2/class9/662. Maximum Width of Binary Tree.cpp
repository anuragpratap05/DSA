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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int level = 0;
    vector<vector<int>> range; // min,max
    int maxWidth = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (level == range.size())
            range.push_back({INT_MAX, INT_MIN});
        while (size--)
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *curRoot = p.first;
            int parIdx = p.second;

            if (parIdx < range[level][0])
                range[level][0] = parIdx;

            if (parIdx > range[level][1])
                range[level][1] = parIdx;

            if (maxWidth < (range[level][1] - range[level][0]) + 1)
            {
                maxWidth = (range[level][1] - range[level][0]) + 1;
            }

            if (curRoot->left)
                q.push({curRoot->left, (2 * parIdx) % 1000000007});
            if (curRoot->right)
                q.push({curRoot->right, ((2 * parIdx) + 1) % 1000000007});
        }
        level++;
    }

    return maxWidth;
}

int main()
{
    return 0;
}