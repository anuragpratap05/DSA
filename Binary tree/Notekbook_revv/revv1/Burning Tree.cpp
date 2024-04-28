#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printkDown(Node *node, Node *blockNd, int time, vector<vector<int>> &ans)
{
    if (node == nullptr or node == blockNd)
        return;

    if (time == ans.size())
        ans.push_back({});
    ans[time].push_back(node->data);
    printkDown(node->left, blockNd, time + 1, ans);
    printkDown(node->right, blockNd, time + 1, ans);
}

int nodeToRootPath(Node *root, int target, vector<vector<int>> &ans)
{
    if (root == nullptr)
        return -1;
    if (root->data == target)
    {
        printkDown(root, nullptr, 0, ans);
        return 1;
    }
    int left = nodeToRootPath(root->left, target, ans);
    if (left > 0)
    {
        printkDown(root, root->left, left, ans);
        return left + 1;
    }
    int right = nodeToRootPath(root->right, target, ans);
    if (right > 0)
    {
        printkDown(root, root->right, right, ans);
        return right + 1;
    }

    return -1;
}

int minTime(Node *root, int target)
{
    if(root==nullptr)
        return 0;
    vector<vector<int>> ans;
    nodeToRootPath(root, target, ans);
    return ans.size();
}

int main()
{
    return 0;
}