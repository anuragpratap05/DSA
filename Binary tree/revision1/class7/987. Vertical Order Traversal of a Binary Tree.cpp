#include <bits/stdc++.h>
using namespace std;
// nhi pass ho rha sayad compara glt likha hai

//jbki ye array me bhrke sort krdo to pass ho rha hai

//PQ wala solun dikkt kr riya hai
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
class trp
{
public:
    TreeNode *node;
    int hl;
    int vl;
    trp(TreeNode *node, int hl, int vl)
    {
        this->node = node;
        this->hl = hl;
        this->vl = vl;
    }
};
class compara
{
public:
    bool operator()(const trp &a, const trp &b) const
    {
        if (a.hl < b.hl)
        {
            return a.hl > b.hl;
        }
        else if (a.hl == b.hl and a.vl < b.vl)
        {
            return a.vl > b.vl;
        }
        return a.node->val >= b.node->val;

        // if (a.hl == b.hl and a.vl == b.vl)
        // {
        //     return a.node->val > b.node->val;
        // }
        // return a.hl >= b.hl;

        // if(a.hl < b.hl)
        // {
        //     return a.hl>b.hl;
        // }
        // return a.node->val > b.node->val;

        // if (a.hl < b.hl)
        // {
        //     return a.hl > b.hl;
        // }
        // else if (a.vl == b.vl)
        // {
        //     return a.node->val > b.node->val;
        // }
        // else if (a.vl < b.vl)
        //     return a.vl > b.vl;
        // else
        //     return a.vl < b.vl;

        // return a[0] > b[0]; // this > other, min PQ.
        //  return b[0] > a[0]; // this > other, max PQ.
    }
};

vector<int> vec;

void shadow(TreeNode *root, int x)
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

vector<vector<int>> vertical_order_traversal(TreeNode *root, int k, int size)
{
    vector<vector<int>> vec(size, vector<int>());

    priority_queue<trp, vector<trp>, compara> q;
    trp t(root, 0, k);

    q.push(t);
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        TreeNode *rn = p.node;
        int hl = p.hl;
        int vl = p.vl;
        vec[vl].push_back(rn->val);
        if (rn->left != nullptr)
        {
            q.push(trp(rn->left, hl + 1, vl - 1));
        }
        if (rn->right != nullptr)
        {
            q.push(trp(rn->right, hl + 1, vl + 1));
        }
    }
    return vec;
}

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vec.resize(2, 0);
    shadow(root, 0);
    int size = (vec[1] - vec[0]) + 1;

    vector<vector<int>> ans = vertical_order_traversal(root, abs(vec[0]), size);
    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    return verticalOrderTraversal(root);
}

int main()
{
    return 0;
}