#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int height=0;
    int bal=0;
    TreeNode(int val)
    {
    this->val = val;
    }
};



void update_bal_height(TreeNode* root)
{
    int lh= (root->left!=nullptr?root->left->height:-1);
    int rh= (root->right!=nullptr?root->right->height:-1);
    root->height=max(lh,rh)+1;
    root->bal=lh-rh;
}
TreeNode* right_rotation(TreeNode* A)
{
    TreeNode* B=A->left;
    TreeNode* b_ka_right=B->right;

    B->right=A;
    A->left = b_ka_right;
    update_bal_height(A);
    update_bal_height(B);
    return B;
}

TreeNode* left_rotation(TreeNode* A)
{
    TreeNode* B=A->right;
    TreeNode* b_ka_left=B->left;

    B->left=A;
    A->right=b_ka_left;
    update_bal_height(A);
    update_bal_height(B);
    return B;
}

TreeNode* get_rotation(TreeNode *root)
{
    update_bal_height(root);
    if(root->bal==2) // ll,lr
    {
        if(root->left->bal==1)// ll
        {
            return right_rotation(root);
        }
        else{// lr
        root->left=left_rotation(root->left);
        return right_rotation(root);
        }

    }
    else if(root->bal==-2)// rr,rl
    {
        if(root->right->bal==-1)//rr
        {
            return left_rotation(root);
        }
        else//rl
        {
            root->right=right_rotation(root->right);
            return left_rotation(root);
            
        }

    }
    return root;
}

TreeNode *getmin(TreeNode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return NULL;
    }

    if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr or root->right == nullptr)
        {
            return (root->left == nullptr ? root->right : root->left);
        }
        else
        {
            TreeNode *temp = getmin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }
    return get_rotation(root);
}
void display(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    string str = "";
    str += (root->left != nullptr ? to_string(root->left->val) : ".");
    str += (" -> " + to_string(root->val) + " <- ");
    str += (root->right != nullptr ? to_string(root->right->val) : ".");
    cout << str << endl;
    display(root->left);
    display(root->right);
}
int main()
{
    TreeNode* root=nullptr;
    for(int i=1;i<=15;i++)
    {
        root=insertIntoBST(root,i*10);
    }
    display(root);

    return 0;
}