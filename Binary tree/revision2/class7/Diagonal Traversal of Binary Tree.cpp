#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val)
    {
        this->val = val;
    }
};

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

vector<int> diagonalIterative(Node *root)
{
    queue<qPair> q;
    q.push(qPair(root, 0));
    vector<vector<int>> ans;

    while (!q.empty())
    {
        qPair curPair = q.front();
        q.pop();

        Node *curRoot = curPair.par;
        int curVerlvl = curPair.verLevel;
        if (ans.size() == curVerlvl)
            ans.push_back({});
        ans[curVerlvl].push_back(curRoot->val);
        if (curRoot->left)
            q.push(qPair(curRoot->left, curVerlvl + 1));
        if (curRoot->right)
            q.push(qPair(curRoot->right, curVerlvl));
    }
    vector<int> finalAns;
    for (vector<int> &vec : ans)
    {
        for (int e : vec)
            finalAns.push_back(e);
    }
    return finalAns;
}

void diagonalRecursive(Node *root, int curVerlevel, vector<vector<int>> &ans)
{
    if (root == nullptr)
        return;
    if (ans.size() == curVerlevel)
        ans.push_back({});
    ans[curVerlevel].push_back(root->val);
    diagonalRecursive(root->left, curVerlevel + 1, ans);
    diagonalRecursive(root->right, curVerlevel, ans);
}

vector<int> diagonal(Node *root)
{
    // return diagonalIterative(root);
    int curVerlevel = 0;
    vector<vector<int>> ans;
    diagonalRecursive(root, curVerlevel, ans);
    vector<int> finalAns;
    for (vector<int> &vec : ans)
    {
        for (int e : vec)
            finalAns.push_back(e);
    }
    return finalAns;
}

int main()
{
    return 0;
}