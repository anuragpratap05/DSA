#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
void printKLevelDown(Node *root, int k, Node *blockNode, vector<vector<int>> &ans)
{
    if (root == nullptr or root == blockNode)
        return;

    if (ans.size() == k)
        ans.push_back({});
    ans[k].push_back(root->data);

    printKLevelDown(root->left, k + 1, blockNode, ans);
    printKLevelDown(root->right, k + 1, blockNode, ans);
}
int nodeToRootPathSpaceOptimized(Node *root, int tar, vector<vector<int>> &ans)
{

    if (root == nullptr)
        return -1;
    if (root->data == tar)
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
int burningTreeSpaceOptimized(Node *root, int target)
{
    vector<vector<int>> ans;
    nodeToRootPathSpaceOptimized(root, target, ans);
    return ans.size();
}
int minTime(Node *root, int target)
{
    return burningTreeSpaceOptimized(root, target)-1;
}

int main()
{
    return 0;
}