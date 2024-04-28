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

TreeNode *giveit(TreeNode *root, TreeNode *c)
{
    while (root->right != nullptr and root->right != c)
    {
        root = root->right;
    }
    return root;
}

TreeNode *morris_inorder(TreeNode *root)
{
    TreeNode *c = root;
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *p = dummy;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            // cout<<c->val;
            c->left = p;
            p->right = c;
            p = p->right;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l, c);
            if (rmnode->right == nullptr)
            {
                rmnode->right = c;
                c = c->left;
            }
            else
            {
                rmnode->right = nullptr;
                // cout<<c->val;
                p->right = c;
                c->left = p;
                p = p->right;
                c = c->right;
            }
        }
    }
    TreeNode *rn = dummy->right;
    dummy->right = nullptr;
    rn->left = nullptr;
    // rn->left = p;
    // p->right = rn;
    return rn;
}

TreeNode *treeToDoublyList(TreeNode *root)
{
    return morris_inorder(root);
}
TreeNode *merge(TreeNode *l1, TreeNode *l2)
{
    if (l1 == nullptr or l2 == nullptr)
    {
        return (l1 == nullptr ? l2 : l1);
    }
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *p = dummy;
    TreeNode *c1 = l1;
    TreeNode *c2 = l2;

    while (c1 != nullptr and c2 != nullptr)
    {
        if (c1->val < c2->val)
        {
            p->right = c1;
            c1->left = p;
            p = c1;
            c1 = c1->right;
        }
        else
        {
            p->right = c2;
            c2->left = p;
            p = c2;
            c2 = c2->right;
        }
    }
    if (c1 == nullptr)
    {
        p->right = c2;
        c2->left = p;
    }
    else
    {
        p->right = c1;
        c1->left = p;
    }
    TreeNode *rn = dummy->right;
    dummy->right = nullptr;
    rn->left = nullptr;
    return rn;
}
TreeNode *midlle(TreeNode *head)
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
TreeNode *sortDoubly(TreeNode *head)
{
    if (head == nullptr or head->right == nullptr)
    {
        return head;
    }

    TreeNode *midnode = midlle(head);
    TreeNode *rh = midnode->right;
    midnode->right = rh->left = nullptr;

    TreeNode *l1 = sortDoubly(head);
    TreeNode *l2 = sortDoubly(rh);

    return merge(l1, l2);
}
TreeNode *Dll_to_bst(TreeNode *head)
{
    if (head == nullptr or head->right == nullptr)
    {
        return head;
    }

    TreeNode *midnode = midlle(head);

    TreeNode *p = midnode->left;
    TreeNode *lh = (p == nullptr ? nullptr : head);
    TreeNode *rh = midnode->right;

    midnode->right = nullptr;
    midnode->left = nullptr;
    rh->left = nullptr;
    if (p != nullptr)
    {
        p->right = nullptr;
    }

    TreeNode *root = midnode;
    root->left = Dll_to_bst(lh);
    root->right = Dll_to_bst(rh);

    return root;
}

void display(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    string str = "";
    str += (root->left != nullptr ? to_string(root->left->val) : ".");
    str+=(" -> "+to_string(root->val)+" <- ");
    str += (root->right != nullptr ? to_string(root->right->val) : ".");
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}

TreeNode *binary_to_BST(TreeNode *root)
{
    if (root == nullptr)
    {
        return NULL;
    }
    TreeNode *head = treeToDoublyList(root);
    head = sortDoubly(head);
    TreeNode *my_root = Dll_to_bst(head);

    return my_root;
}
int main()
{
    return 0;
}