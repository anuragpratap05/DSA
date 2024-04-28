#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *right = nullptr;
    ListNode(int val)
    {
        this->val = val;
    }
};
ListNode *midNode(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode *s = head;
    ListNode *f = head;

    while (f->next != nullptr and f->next->next != nullptr)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode *p = nullptr;
    ListNode *c = head;

    while (c != nullptr)
    {
        ListNode *f = c->next;
        c->next = p;
        p = c;
        c = f;
    }
    return p;
}
void reorderList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return;
    }

    ListNode *mid = midNode(head);

    ListNode *agla = mid->next;
    mid->next = nullptr;

    ListNode *c2 = reverseList(agla);
    ListNode *c1 = head;

    while (c1 != nullptr and c2 != nullptr)
    {
        ListNode *f1 = c1->next;
        ListNode *f2 = c2->next;

        c1->next = c2;
        c2->next = f1;

        c1 = f1;
        c2 = f2;
    }
}

int main()
{
    return 0;
}