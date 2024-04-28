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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *a = head;
    ListNode *b = head;

    while (n--)
    {
        b = b->next;
    }
    if (b == nullptr)
    {
        return a->next;
    }
    while (b->next != nullptr)
    {
        b = b->next;
        a = a->next;
    }
    a->next = a->next->next;
    return head;
}

int main()
{
    return 0;
}