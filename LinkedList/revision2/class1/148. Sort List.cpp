#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr or list2 == nullptr)
    {
        return (list1 == nullptr ? list2 : list1);
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;

    ListNode *c1 = list1;
    ListNode *c2 = list2;

    while (c1 != nullptr and c2 != nullptr)
    {
        if (c1->val < c2->val)
        {
            p->next = c1;
            p = p->next;

            c1 = c1->next;
        }
        else
        {
            p->next = c2;
            p = p->next;

            c2 = c2->next;
        }
    }
    if (c1 == nullptr)
    {
        p->next = c2;
    }
    else
    {
        p->next = c1;
    }
    return dummy->next;
}
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
ListNode *sortList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode *mid = midNode(head);
    ListNode *nh = mid->next;

    mid->next = nullptr;
    ListNode *left = sortList(head);
    ListNode *right = sortList(nh);
    return mergeTwoLists(left, right);
}

int main()
{
    return 0;
}