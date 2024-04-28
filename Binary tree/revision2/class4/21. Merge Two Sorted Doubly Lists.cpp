#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr or list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

    ListNode *dummy = new ListNode(-1), *p = dummy;
    ListNode *c1 = list1, *c2 = list2;

    while (c1 and c2)
    {
        if (c1->val < c2->val)
        {
            p->next = c1;
            c1->prev = p;
            p = c1;
            c1 = c1->next;
        }
        else
        {
            p->next = c2;
            c2->prev = p;
            p = c2;
            c2 = c2->next;
        }
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
    ListNode *hd = dummy->next;
    dummy->next = nullptr;
    hd->prev = nullptr;
    return hd;
}

int main()
{
    return 0;
}