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

int height(TreeNode* root)
{
    if(root==nullptr)
    {
        return -1;

    }

    int lh=height(root->left);
    int rh = height(root->right);

    return max(lh,rh)+1;
}


int diameterOfBinaryTree(TreeNode *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int ld=diameterOfBinaryTree(root->left);
    int rd=diameterOfBinaryTree(root->right);

    int lh=height(root->left);
    int rh=height(root->right);

    int my_dia=max(max(ld,rd),lh+rh+2);
    return my_dia;
}

class pair_
{
    public:
    int height;
    int dia;
};
pair_ diameterOfBinaryTree2_help(TreeNode *root)
{
    if(root==nullptr)
    {
        pair_ base;
        base.height=-1;
        base.dia=0;
        return base;

    }

    pair_ left=diameterOfBinaryTree2_help(root->left);
    pair_ right=diameterOfBinaryTree2_help(root->right);

    pair_ mypair;
    mypair.height=max(left.height,right.height)+1;
    mypair.dia=max(max(left.dia,right.dia),left.height+right.height+2);
    return mypair;


}

int diameterOfBinaryTree2(TreeNode *root)
{

}

int main()
{
    return 0;
}