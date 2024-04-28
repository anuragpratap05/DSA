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
TreeNode *construct(int post[], int lr, int rr,int size,int& i)
{
    //int i = vec[0];
    int ele;
    if (i >= 0)
    {
        ele = post[i];
    }
    if (ele < lr or ele > rr or i <0)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(ele);
    i--;
    root->right = construct(post, ele, rr,size, i);
    root->left = construct(post, lr, ele,size, i);
    return root;
}
TreeNode *constructTree(int post[], int size)
{
    int i=size-1;
    return construct(post,-1e9,1e9,size,i);
}

int main()
{
    return 0;
}