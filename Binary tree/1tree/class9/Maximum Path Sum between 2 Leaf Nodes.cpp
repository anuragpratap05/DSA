#include <bits/stdc++.h>
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
class pair_
{
public:
    int maxsum;
    int ht;
};
// gfg
pair_ maxPathSum2(Node *root)
{
    if (root->left == nullptr and root->right == nullptr)
    {
        pair_ base;

        base.maxsum = -10000;
        base.ht = root->data;
        return base;
    }
    pair_ left;
    pair_ right;
    if (root->left != nullptr)
        left = maxPathSum2(root->left);
    if (root->right != nullptr)
        right = maxPathSum2(root->right);

    if (root->left == nullptr)
    {
        right.ht += root->data;
        return right;
    }
    if (root->right == nullptr)
    {
        left.ht += root->data;
        return left;
    }
    pair_ mypair;
    // cout<<left.maxsum<<endl;
    mypair.maxsum = max(max(left.maxsum, right.maxsum), left.ht + right.ht + root->data);
    mypair.ht = max(left.ht, right.ht) + root->data;
    return mypair;
}
int maxPathSum(Node *root)
{

    pair_ p = maxPathSum2(root);

    int ans1 = p.maxsum;
    int ans2 = p.ht;

    if (ans1 == -10000)
    {
        return ans2;
    }
    return ans1;
}

int main()
{
    return 0;
}