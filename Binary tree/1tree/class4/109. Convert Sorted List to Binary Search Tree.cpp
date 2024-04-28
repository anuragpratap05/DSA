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

class ListNode
{
public:
    int val = 0;
    // ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode(int val)
    {
        this->val = val;
    }
};
vector<ListNode *> midlle(ListNode *head)
{
    if(head==nullptr or head->next==nullptr)
    {
        if(head==nullptr)
        {
            return { nullptr, nullptr };
        }
        return { nullptr ,head};
    }
    ListNode *s = head;
    ListNode *f = head;
    ListNode *p = nullptr;
    while (f->next != nullptr and f->next->next != nullptr)
    {
        p = s;
        s = s->next;
        f = f->next->next;
    }
    return {p, s};
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    vector<ListNode *> vec = midlle(head);

    ListNode *p = vec[0];
    ListNode *midnode = vec[1];
    ListNode *lh = (p == nullptr ? nullptr : head);
    ListNode *rh = midnode->next;
    midnode->next = nullptr;

    if (p != nullptr)
    {
        p->next = nullptr;
    }

    TreeNode *root = new TreeNode(midnode->val);

    root->left = sortedListToBST(lh);
    root->right = sortedListToBST(rh);
    return root;
}

int main()
{
    return 0;
}