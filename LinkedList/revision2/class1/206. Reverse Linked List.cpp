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

int main()
{
    return 0;
}