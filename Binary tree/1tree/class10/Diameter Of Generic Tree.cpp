#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};
class Node
{
public:
    int data;
    vector<Node *> children;
};

//method 1
vector<int> diameter2(Node *root)
{
    // vector<int> ans(2,0);
    int d = 0;
    int h1 = -1, h2 = -1;
    // vec[0] = vec[1] = 0;
    for (Node *child : root->children)
    {
        vector<int> ans = diameter2(child);
        if (ans[1] > h1)
        {
            h2 = h1;
            h1 = ans[1];
        }
        else if (ans[1] > h2)
        {
            h2 = ans[1];
        }
        d = max(ans[0], d);
    }
    return {max(d, h1 + h2 + 2), max(h1, h2) + 1};
}
// method 2
int d = 0;
int diameter_static(Node *root)
{
    // vector<int> ans(2,0);

    int h1 = -1, h2 = -1;
    // vec[0] = vec[1] = 0;
    for (Node *child : root->children)
    {
        int ans = diameter_static(child);
        if (ans > h1)
        {
            h2 = h1;
            h1 = ans;
        }
        else if (ans > h2)
        {
            h2 = ans;
        }
    }
    d = max(d, h1 + h2 + 2);
    return  max(h1, h2) + 1;
}
int diameter(Node *root)
{
    return diameter2(root)[0];
}

int main()
{
    return 0;
}