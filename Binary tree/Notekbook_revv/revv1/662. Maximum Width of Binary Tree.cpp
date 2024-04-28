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

    int maxWidth = 0;

    vector<vector<int>> vec;
    int level = 0;

    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        if (vec.size() == level)
            vec.push_back({INT_MAX, INT_MIN});
        while (size--)
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();

            TreeNode *curNode = p.first;
            int curBoundry = p.second;
            // vec[level][0] = min(vec[level][0], curBoundry);
            if (curBoundry < vec[level][0])
                vec[level][0] = curBoundry;
            // vec[level][1] = max(vec[level][1], curBoundry);
            if (curBoundry > vec[level][1])
                vec[level][1] = curBoundry;
            // maxWidth = max(maxWidth, (vec[level][1] - vec[level][0]) + 1);
            if ((vec[level][1] - vec[level][0]) + 1 > maxWidth)
                maxWidth = (vec[level][1] - vec[level][0]) + 1;
            if (curNode->left)
                q.push({curNode->left, 2 * curBoundry});
            if (curNode->right)
                q.push({curNode->right, (2 * curBoundry) + 1});
        }
        level++;
    }
    return maxWidth;
}

int main()
{
    return 0;
}