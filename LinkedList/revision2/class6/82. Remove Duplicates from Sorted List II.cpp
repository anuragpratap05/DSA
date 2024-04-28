#include<bits/stdc++.h>
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
    ListNode *c = head;
    ListNode *dummy = new ListNode(-101);
    ListNode *p = dummy;
    while (c != nullptr)
    {
        bool loopChla = false;
        int value = c->val;
        ListNode *node = c;
        c = c->next;
        while (c != nullptr and c->val == value)
        {
            loopChla = true;
            c = c->next;
        }
        if(!loopChla)
        {
            p->next = node;
            p = p->next;
        }
    }
    p->next = nullptr;
    return dummy->next;
}

int main()
{
    return 0;
}