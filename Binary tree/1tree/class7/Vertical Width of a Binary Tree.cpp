#include<bits/stdc++.h>
using namespace std;

// gfg
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
int verticalWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    vector<int> vec(2, 0);
    width(root, 0, vec);
    return (vec[1] - vec[0]) + 1; // Code here
}

int main()
{
    return 0;
}