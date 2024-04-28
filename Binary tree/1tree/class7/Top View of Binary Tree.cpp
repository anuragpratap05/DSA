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

void level_order(Node *root, vector<int> &ans, int level)
{
    queue<pair<Node *, int>> q;
    q.push({root, level});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *rn = p.first;
        int c_level = p.second;
        if(ans[c_level]==-1)
        {
            ans[c_level] = rn->data;
        }
        
        if (rn->left != nullptr)
        {
            q.push({rn->left, c_level - 1});
        }
        if (rn->right != nullptr)
        {
            q.push({rn->right, c_level + 1});
        }
    }
}
void width(Node *root, int idx, vector<int> &vec)
{
    if (root == nullptr)
    {
        return;
    }
    vec[0] = min(vec[0], idx);
    vec[1] = max(vec[1], idx);
    width(root->left, idx - 1, vec);
    width(root->right, idx + 1, vec);
    return;
}
// Function to find the vertical width of a Binary Tree.
pair<int, int> verticalWidth(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    vector<int> vec(2, 0);
    width(root, 0, vec);
    int size = (vec[1] - vec[0]) + 1;
    int mindata = vec[0];
    return {size, mindata};
}
vector<int> verticalOrder(Node *root)
{
    pair<int, int> p = verticalWidth(root);

    int size = p.first;
    int mindata = p.second;
    vector<int> ans(size,-1);
    level_order(root, ans, abs(mindata));
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