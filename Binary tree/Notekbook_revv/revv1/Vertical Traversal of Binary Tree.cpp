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

int leftMin = 0, rightMax = 0;

void getBoundries(Node *root, int curVerLevel)
{
    if (root == nullptr)
        return;
    leftMin = min(leftMin, curVerLevel);
    rightMax = max(rightMax, curVerLevel);
    getBoundries(root->left, curVerLevel - 1);
    getBoundries(root->right, curVerLevel + 1);
    return;
}

vector<int> verticalOrder(Node *root)
{
    if (root == nullptr)
        return {};
    getBoundries(root, 0);
    int n = (rightMax - leftMin) + 1;
    vector<vector<int>> ans(n, vector<int>());

    // root, level
    queue<pair<Node *, int>> q;

    q.push({root, abs(leftMin)});
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *node = p.first;
            int verLevel = p.second;

            ans[verLevel].push_back(node->data);
            if (node->left)
                q.push({node->left, verLevel - 1});
            if (node->right)
                q.push({node->right, verLevel + 1});
        }
        level++;
    }
    vector<int> finaalAns;
    for (vector<int> &vec : ans)
    {
        for (int e : vec)
            finaalAns.push_back(e);
    }
    return finaalAns;
}

int main()
{
    return 0;
}