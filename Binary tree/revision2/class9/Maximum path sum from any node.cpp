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

class NodeInfo
{
public:
    int maxTreeSum = -1e8;
    int maxPathSum = 0;
};

NodeInfo maxPathSumHelp(Node *root)
{
    if (root == nullptr)
    {
        NodeInfo base;
        return base;
    }

    NodeInfo left = maxPathSumHelp(root->left);
    NodeInfo right = maxPathSumHelp(root->right);

    NodeInfo curNode;

    curNode.maxTreeSum = max(root->data, max(left.maxPathSum + right.maxPathSum + root->data, max(root->data + max(left.maxPathSum, right.maxPathSum), max(left.maxTreeSum, right.maxTreeSum))));

    curNode.maxPathSum = max(root->data, root->data + max(left.maxPathSum, right.maxPathSum));

    return curNode;
}
int findMaxSum(Node *root)
{
    return maxPathSumHelp(root).maxTreeSum;
}

int main()
{
    return 0;
}