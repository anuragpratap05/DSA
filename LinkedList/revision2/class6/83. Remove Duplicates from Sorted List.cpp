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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode *c = head;
    ListNode *dummy = new ListNode(-101);
    ListNode *p = dummy;
    while (c != nullptr)
    {
        while (c != nullptr and c->val == p->val)
        {
            c = c->next;
        }
        if (c != nullptr)
        {
            p->next = c;
            p = p->next;
            c = c->next;
        }
    }
    p->next = nullptr;
    return dummy->next;
}

int main()
{
    return 0;
}