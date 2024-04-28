#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int data = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int data)
    {
    this->data = data;
    }
};
TreeNode * midlle(TreeNode *head)
{
    if (head == nullptr or head->right == nullptr)
    {
        return head;
    }
    TreeNode *s = head;
    TreeNode *f = head;
    while (f->right != nullptr and f->right->right != nullptr)
    {
        
        s = s->right;
        f = f->right->right;
    }
    return s;
}
TreeNode* Dll_to_bst(TreeNode* head)
{
    if(head==nullptr or head->right==nullptr)
    {
        return head;
    }

    TreeNode* midnode=midlle(head);

    TreeNode* p=midnode->left;
    TreeNode* lh= (p==nullptr?nullptr:head);
    TreeNode* rh=midnode->right;

    midnode->right=nullptr;
    midnode->left=nullptr;
    rh->left=nullptr;
    if(p!=nullptr)
    {
        p->right=nullptr;
    }

    TreeNode* root=midnode;
    root->left=Dll_to_bst(lh);
    root->right = Dll_to_bst(rh);

    return root;
}

int main()
{
    return 0;
}