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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    ListNode *c = head, *p = nullptr, *nh = nullptr;

    while (c)
    {
        bool loopRans = false;
        int uniqVal = c->val;
        ListNode *f = c->next;
        while (f and uniqVal == f->val)
        {
            f = f->next;
            loopRans = true;
        }
        if (!loopRans)
        {
            if (p)
                p->next = c;
            p = c;
            if (nh == nullptr)
                nh = p;
        }
        c = f;
        if (p)
            p->next = nullptr;
    }
    return nh;
}

int main()
{
    return 0;
}