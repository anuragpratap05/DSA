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

ListNode *mergeTwoSortedLL(ListNode *h1, ListNode *h2)
{
    if (h1 == nullptr or h2 == nullptr)
        return h1 == nullptr ? h2 : h1;

    ListNode *dummy = new ListNode(-1), *p = dummy, *c1 = h1, *c2 = h2;

    while (c1 and c2)
    {
        if (c1->val < c2->val)
        {
            p->next = c1;
            p = c1;
            c1 = c1->next;
        }
        else
        {
            p->next = c2;
            p = c2;
            c2 = c2->next;
        }
    }

    p->next = c1 ? c1 : c2;
    ListNode *nHead = dummy->next;
    dummy->next = nullptr;
    return nHead;
}

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

ListNode *sortList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *mid = midNode(head);
    ListNode *h2 = mid->next;
    mid->next = nullptr;

    ListNode *leftSorted = sortList(head);
    ListNode *rightSorted = sortList(h2);

    return mergeTwoSortedLL(leftSorted, rightSorted);
}

int main()
{
    return 0;
}