#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> levelOrder(Node *node)
{
    vector<vector<int>> sa;
    queue<Node *> q;
    q.push(node);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node *root = q.front();
            q.pop();
            if (root == nullptr)
                continue;
            if (level == sa.size())
                sa.push_back({});
            sa[level].push_back(root->data);
            q.push(root->left);
            q.push(root->right);
        }
        level++;
    }
    vector<int> ans;
    for (vector<int> &vec : sa)
    {
        for (int ele : vec)
            ans.push_back(ele);
    }
    return ans;
}

int main()
{
    return 0;
}