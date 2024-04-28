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

void print_k_down(Node *root, int k, vector<vector<int>> &ans, Node *block)
{
    if (root == nullptr or root == block)
    {
        return;
    }
    if (k == ans.size())
    {
        ans.push_back({});
    }

    //ans[k].push_back(root->data);

    print_k_down(root->left, k + 1, ans, block);
    print_k_down(root->right, k + 1, ans, block);
}
int distanceK_btr_help(Node *root, int target, vector<vector<int>> &ans)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->data == target)
    {
        print_k_down(root, 0, ans, nullptr);
        return 1;
    }

    int lc = distanceK_btr_help(root->left, target, ans);
    if (lc != 0)
    {
        print_k_down(root, lc, ans, root->left);
        return lc + 1;
    }

    int rc = distanceK_btr_help(root->right, target, ans);
    if (rc != 0)
    {
        print_k_down(root, rc, ans, root->right);
        return rc + 1;
    }
    return 0;
}

int burning_tree(Node *root, int target)
{
    vector<vector<int>> ans;
    distanceK_btr_help(root, target, ans);
    return ans.size()-1;
    
}
int minTime(Node *root, int target)
{
    return burning_tree(root,target);
}

int main()
{
    return 0;
}