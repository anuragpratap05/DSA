#include <bits/stdc++.h>
using namespace std;

// shi nhi chal rha hai

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

void unfold(ListNode *head)
{
    ListNode *c1 = head;
    ListNode *c2 = head->next;
    ListNode *nh = head->next;

    while (c1->next != nullptr and c1->next->next != nullptr)
    {
        c1->next = c1->next->next;
        c2->next = c2->next->next;
        c1 = c1->next;
        c2 = c2->next;
    }
    if (c2 != nullptr)
    {
        c1->next = nullptr;
    }
    nh = reverseList(nh);
    c1->next = nh;
}

int main()
{
    return 0;
}