#include <bits/stdc++.h>
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





TreeNode *middle(TreeNode *root)
{
    TreeNode *s = root;
    TreeNode *f = root;
    while (f->right != nullptr and f->right->right != nullptr)
    {
        s = s->right;
        f = f->right->right;
    }
    return s;
}

TreeNode *SortedDLLToBST_help(TreeNode *head)
{
    if (head == nullptr or head->right == nullptr)
    {
        return head;
    }
    TreeNode *midnode = middle(head);
    TreeNode *p = midnode->left;
    TreeNode *f = midnode->right;
    midnode->left = midnode->right = f->left = nullptr;
    if (p != nullptr)
    {
        p->right = nullptr;
    }
    midnode->left = SortedDLLToBST_help((p == nullptr ? nullptr : head));
    midnode->right = SortedDLLToBST_help(f);
    return midnode;
}

TreeNode *Sorted_DLL_To_BST(TreeNode *head)
{
    return SortedDLLToBST_help(head);
}






TreeNode *giverm(TreeNode *root, TreeNode *c)
{
    while (root->right != nullptr and root->right != c)
    {
        root = root->right;
    }
    return root;
}

TreeNode *morris_inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *p = dummy;

    TreeNode *curr = root;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            // cout<<curr->val;
            p->right = curr;
            curr->left = p;
            p = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnode = giverm(l, curr);
            if (rmnode->right == nullptr)
            {
                rmnode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnode->right = nullptr;
                p->right = curr;
                curr->left = p;
                p = curr;
                curr = curr->right;
            }
        }
    }
    TreeNode *rn = dummy->right;
    dummy->right = nullptr;
    rn->left = nullptr;
    p->right = nullptr;
    return rn;
}
TreeNode *treeToDoublyList(TreeNode *root)
{
    return morris_inorder(root);
}





TreeNode *merge(TreeNode* l1,TreeNode* l2)
{
    if(l1==nullptr or l2==nullptr)
    {
        if(l1==nullptr)
        {
            return l2;

        }
        return l1;
    }
    TreeNode* c1=l1;
    TreeNode* c2=l2;
    TreeNode* dummy=new TreeNode(-1);
    TreeNode* p=dummy;

    while(c1!=nullptr and c2!=nullptr)
    {
        if(c2->val<c1->val)
        {
            p->right=c2;
            c2->left=p;
            p=c2;
            c2=c2->right;
        }
        else{
            p->right = c1;
            c1->left = p;
            p = c1;
            c1 = c1->right;
        }
    }
    if(c1==nullptr)
    {
        while(c2!=nullptr)
        {
            p->right=c2;
            c2->left = p;
            p = c2;
            c2 = c2->right;
        }
    }
    else
    {
        while (c1 != nullptr)
        {
            p->right = c1;
            c1->left = p;
            p = c1;
            c1 = c1->right;
        }
    }
    TreeNode* rv=dummy->right;
    dummy->right=nullptr;
    rv->left=nullptr;
    return rv;

}

TreeNode* sort_linked_list(TreeNode* root)
{
    if(root==nullptr or root->right==nullptr)
    {
        return root;
    }
    TreeNode* midTreeNode=middle(root);
    TreeNode* f=midTreeNode->right;
    midTreeNode->right=nullptr;
    f->left=nullptr;

    TreeNode* l1=sort_linked_list(root);
    TreeNode* l2=sort_linked_list(f);

    return merge(l1,l2);

}



TreeNode* binary_tree_to_BST(TreeNode* root)
{
    root=treeToDoublyList(root);
    root = sort_linked_list(root);
    return Sorted_DLL_To_BST(root);
}

int main()
{
    return 0;
}