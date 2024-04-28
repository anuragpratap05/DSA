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

class p
{
public:
    int max_sum_so_far = 0;
    int max_path = 0;
};

p maxPathSum_help(Node *root)
{
    if(root==nullptr)
    {
        p x;
        return x;
    }

    p left = maxPathSum_help(root->left);
    p right = maxPathSum_help(root->right);

    p myp;
    myp.max_path = max(left.max_path, right.max_path) + root->data;

    if(root->left!=nullptr and root->right!=nullptr)
    {
        myp.max_sum_so_far = max(max(left.max_sum_so_far, right.max_sum_so_far), (left.max_path + right.max_path) + root->data);
    }
    else
    {
        myp.max_sum_so_far = (root->left == nullptr ? right.max_sum_so_far : left.max_sum_so_far);
    }
    return myp;
}

int maxPathSum(Node *root)
{
    return maxPathSum_help(root).max_sum_so_far;
}

int main()
{
    return 0;
}