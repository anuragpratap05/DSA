#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *midNode(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    ListNode *s = head, *f = head;

    while (f->next and f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    ListNode *p = nullptr, *c = head;
    while (c != nullptr)
    {
        ListNode *f = c->next;
        c->next = p;
        p = c;
        c = f;
    }
    return p;
}

ListNode *reorderList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    ListNode *mid = midNode(head);
    ListNode *h2 = mid->next;
    mid->next = nullptr;

    h2 = reverseList(h2);
    ListNode *c1 = head, *c2 = h2;
    while (c1 and c2)
    {
        ListNode *f1 = c1->next, *f2 = c2->next;
        c1->next = c2;
        c2->next = f1;
        c1 = f1;
        c2 = f2;
    }
    return head;
}

int main()
{
    return 0;
}