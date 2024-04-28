#include<bits/stdc++.h>
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
// method 1
void diagonal_print(Node *root, int level, vector<vector<int>> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back({});
    }
    ans[level].push_back(root->data);
    diagonal_print(root->left, level + 1, ans);
    diagonal_print(root->right, level, ans);
}
// method 2 using queue
void diagonal2(Node *root, vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *rn = q.front();
        q.pop();
        // ans.push_back(rn->data);
        while (rn != nullptr)
        {
            ans.push_back(rn->data);
            if (rn->left != nullptr)
            {
                q.push(rn->left);
            }
            rn = rn->right;
        }
    }
}

vector<int> diagonal(Node *root)
{

    vector<vector<int>> ans(0, vector<int>());
    diagonal_print(root, 0, ans);
    vector<int> final;

    for (vector<int> &vec : ans)
    {
        for (int e : vec)
        {
            final.push_back(e);
        }
    }
    return final;
}

int main()
{
    return 0;
}