#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next = nullptr;
    // ListNode()
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    ListNode *curr = head, *prev = nullptr;

    while (curr != nullptr)
    {
        ListNode *forw = curr->next;
        // if (curr->next)
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

int main()
{
    return 0;
}