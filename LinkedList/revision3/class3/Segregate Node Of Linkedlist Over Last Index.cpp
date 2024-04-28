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

ListNode *segregateOnLastIndex(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *cur = head;

    int lastval;
    while (cur != nullptr)
    {
        lastval = cur->val;
        cur = cur->next;
    }
    cur = head;
    ListNode *smallHd = new ListNode(-1);
    ListNode *small = smallHd;
    ListNode *largeHd = new ListNode(-1);
    ListNode *large = largeHd;

    while (cur->next != nullptr)
    {
        if (cur->val < lastval)
        {
            small->next = cur;
            small = small->next;
        }
        else
        {
            large->next = cur;
            large = large->next;
        }
        cur = cur->next;
    }
    small->next = nullptr;
    large->next = nullptr;
    cur->next = largeHd->next;
    small->next = cur;
    return small->next;
}

int main()
{
    return 0;
}