#include<bits/stdc++.h>
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
int c = 0;
class p
{
public:
    bool need = false;
    bool hai = false;
};

p minCameraCover_help(TreeNode *root)
{
    if(root==nullptr)
    {
        p x;
        return x;
    }
    p left = minCameraCover_help(root->left);
    p right = minCameraCover_help(root->right);
    p myp;

    if(left.need or right.need)
    {
        c += 1;
        myp.hai = true;
    }
    else if(left.hai or right.hai)
    {
        myp.need = false;
    }
    else 
    {
        myp.need = true;
    }
    
    return myp;
}

int minCameraCover(TreeNode *root)
{
    p ans = minCameraCover_help(root);
    if(ans.need)
    {
        c += 1;
    }
    return c;
}

int main()
{
    return 0;
}