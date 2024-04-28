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

void printKLevelDown(TreeNode *root, int k, TreeNode *blockNode, vector<vector<int>> &ans)
{
    if (root == nullptr or root == blockNode)
        return;

    if (ans.size() == k)
        ans.push_back({});
    ans[k].push_back(root->val);

    printKLevelDown(root->left, k + 1, blockNode, ans);
    printKLevelDown(root->right, k + 1, blockNode, ans);
}

// bool nodeToRootPath(TreeNode *root, int tar, vector<TreeNode *> &ans)
// {
//     if (root == nullptr)
//         return false;
//     if (root->val == tar)
//     {
//         ans.push_back(root);
//         return true;
//     }
//     bool found = nodeToRootPath(root->left, tar, ans) || nodeToRootPath(root->right, tar, ans);
//     if (found)
//         ans.push_back(root);
//     return found;
// }

// vector<vector<int>> burningTree(TreeNode *root, int target)
// {
//     vector<TreeNode *> nodeToroot;
//     nodeToRootPath(root, target, nodeToroot);
//     vector<vector<int>> ans;
//     for (int i = 0; i < nodeToroot.size(); i++)
//     {
//         TreeNode *blockNode = i == 0 ? nullptr : nodeToroot[i - 1];
//         printKLevelDown(nodeToroot[i], i, blockNode, ans);
//     }
//     return ans;
// }

int nodeToRootPathSpaceOptimized(TreeNode *root, int tar, vector<vector<int>> &ans)
{
    // cout<<"aya";

    if (root == nullptr)
        return -1;
    if (root->val == tar)
    {
        printKLevelDown(root, 0, nullptr, ans);
        return 0;
    }

    int lfound = nodeToRootPathSpaceOptimized(root->left, tar, ans);
    if (lfound >= 0)
    {
        lfound++;
        printKLevelDown(root, lfound, root->left, ans);
        return lfound;
    }

    int rfound = nodeToRootPathSpaceOptimized(root->right, tar, ans);
    if (rfound >= 0)
    {
        rfound++;
        printKLevelDown(root, rfound, root->right, ans);
        return rfound;
    }

    return -1;
}

vector<vector<int>> burningTreeSpaceOptimized(TreeNode *root, int target)
{
    vector<vector<int>> ans;
    nodeToRootPathSpaceOptimized(root, target, ans);
    return ans;
}

int main()
{
    // vector<vector<int>> ans = burningTreeSpaceOptimized(root, 14);
    // for (vector<int> &vec : ans)
    // {
    //     for (int e : vec)
    //     {
    //         cout << e << " ,";
    //     }
    //     cout << endl;
    // }
    return 0;
}