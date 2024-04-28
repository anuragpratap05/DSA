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

ListNode *isCyclic(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head;

    while (f != nullptr and f->next != nullptr)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
        {
            break;
        }
    }
    return f;
}
ListNode *detectCycle(ListNode *head)
{
    ListNode *mp = isCyclic(head);
    if (mp == nullptr or mp->next == nullptr)
    {
        return nullptr;
    }
    ListNode *s = head;
    ListNode *f = mp;
    while (s != f)
    {
        s = s->next;
        f = f->next;
    }
    return s;
}

int main()
{
    return 0;
}