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

struct Node
{
    int data;
    struct Node *next, *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node *midOfList(Node *head)
{
    Node *curr = head;
    if (curr == nullptr or curr->next == nullptr)
        return curr;
    Node *s = curr;
    Node *f = curr;
    while (f->next != nullptr and f->next->next != nullptr)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

void createLinks(Node *&curr, Node *&p)
{
    p->next = curr;
    curr->prev = p;
    p = curr;
    curr = curr->next;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == nullptr or list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

    Node *dummy = new Node(-1), *p = dummy;
    Node *c1 = list1, *c2 = list2;

    while (c1 and c2)
    {
        if (c1->data < c2->data)
            createLinks(c1, p);
        else
            createLinks(c2, p);
    }
    if (c1)
    {
        p->next = c1;
        c1->prev = p;
    }
    else
    {
        p->next = c2;
        c2->prev = p;
    }
    Node *hd = dummy->next;
    dummy->next = nullptr;
    hd->prev = nullptr;
    return hd;
}

struct Node *sortDoubly(struct Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *midNode = midOfList(head);
    Node *f = midNode->next;
    midNode->next = nullptr;
    f->prev = nullptr;

    Node *leftSortedList = sortDoubly(head);
    Node *rightSortedList = sortDoubly(f);
    return mergeTwoLists(leftSortedList, rightSortedList);
}

int main()
{
    return 0;
}