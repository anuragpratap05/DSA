#include<bits/stdc++.h>
using namespace std;

// bott hard😂
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
vector<int> height;

void update_ht(TreeNode *root)
{
    int lh = (root->left != nullptr ? height[root->left->val] : -1);
    int rh = (root->right != nullptr ? height[root->right->val] : -1);

    height[root->val] = max(lh, rh) + 1;
}
int getbal(TreeNode *root)
{
    int lh = (root->left != nullptr ? height[root->left->val] : -1);
    int rh = (root->right != nullptr ? height[root->right->val] : -1);
    return lh - rh;
}
TreeNode *get_rotation(TreeNode *root)
{
    update_ht(root);
    if (getbal(root) >= 2) // ll,lr
    {
        if (getbal(root->left) >= 1) // ll
        {
            // cout<<"ll"<<endl;
            return right_rotation(root);
        }
        else
        { // lr
            // cout<<"lr"<<endl;
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }
    else if (getbal(root) <= -2) // rr,rl
    {
        if (getbal(root->right) <= -1) // rr
        {
            // cout<<"rr"<<endl;
            TreeNode *x = left_rotation(root);
            // display(x);
            return x;
        }
        else // rl
        {
            // cout<<"rl"<<endl;
            // cout<<root->val<<"  ";
            // cout<<getbal(root->right);
            // cout<<endl;
            root->right = right_rotation(root->right);
            TreeNode *x = left_rotation(root);
            // display(x);
            return x;
        }
    }

    return root;
}
TreeNode *right_rotation(TreeNode *A)
{
    TreeNode *B = A->left;
    TreeNode *b_ka_right = B->right;

    B->right = A;
    A->left = b_ka_right;

    B->right = get_rotation(A);
    return get_rotation(B);
}

TreeNode *left_rotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *b_ka_left = B->left;

    B->left = A;
    A->right = b_ka_left;

    B->left = get_rotation(A);
    return get_rotation(B);
}


TreeNode *balanceBST2(TreeNode *root)
{
    //[19,10,null,4,17,null,5]
    // p\op=[7,1,11,null,2,9,15,null,3,null,null,14,17,null,null,12]
    // ex=[9,2,14,1,3,11,15,null,null,null,7,null,12,null,17]
    if (root == nullptr)
    {
        return nullptr;
    }

    root->left = balanceBST2(root->left);
    root->right = balanceBST2(root->right);

    // int bal=getbal(root);
    // cout<<root->val<<" "<<bal<<endl;
    return get_rotation(root);
}

TreeNode *balanceBST(TreeNode *root)
{
    height.resize(1e5 + 1, -1);
    return balanceBST2(root);
}

int main()
{
    return 0;
}