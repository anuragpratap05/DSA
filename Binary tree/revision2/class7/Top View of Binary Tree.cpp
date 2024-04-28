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
int leftMin = 1e9;
int rightMax = -1e9;

void findBoundries(Node *root, int level)
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
    Node *par;
    int verLevel;
    qPair(Node *par, int verLevel)
    {
        this->par = par;
        this->verLevel = verLevel;
    }
};

vector<int> verticalOrder(Node *root)
{
    findBoundries(root, 0);
    int width = (rightMax - leftMin) + 1;
    vector<int> ans(width, 0);
    queue<qPair> q;

    q.push(qPair(root, abs(leftMin)));

    while (!q.empty())
    {
        qPair rootPair = q.front();
        q.pop();
        Node *curRoot = rootPair.par;
        int curVerLevel = rootPair.verLevel;

        // ans[curVerLevel].push_back(curRoot->data);
        if (ans[curVerLevel] == 0)
            ans[curVerLevel] = curRoot->data;
        if (curRoot->left)
            q.push(qPair(curRoot->left, curVerLevel - 1));
        if (curRoot->right)
            q.push(qPair(curRoot->right, curVerLevel + 1));
    }
    return ans;
}

vector<int> topView(Node *root)
{
    return verticalOrder(root);
}

int main()
{
    return 0;
}