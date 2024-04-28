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
vector<int> vec;

void shadow(Node *root, int x)
{
    if (root == nullptr)
    {
        return;
    }
    vec[0] = min(vec[0], x);
    vec[1] = max(vec[1], x);
    shadow(root->left, x - 1);
    shadow(root->right, x + 1);
}

vector<int> vertical_order_traversal(Node *root, int k, int size)
{
    vector<int> vec(size,-1);

    queue<pair<Node *, int>> q;

    q.push({root, k});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *rn = p.first;
        k = p.second;
        if(vec[k]==-1)
        {
            vec[k] = rn->data;
        }
        if (rn->left != nullptr)
        {
            q.push({rn->left, k - 1});
        }
        if (rn->right != nullptr)
        {
            q.push({rn->right, k + 1});
        }
    }
    return vec;
}
vector<int> topView(Node *root)
{
    vec.resize(2, 0);
    shadow(root, 0);
    int size = (vec[1] - vec[0]) + 1;
    return vertical_order_traversal(root,abs(vec[0]),size);
}

int main()
{
    return 0;
}