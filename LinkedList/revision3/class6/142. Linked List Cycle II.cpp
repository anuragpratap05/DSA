#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *hasCycle(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return nullptr;

    ListNode *slow = head, *fast = head;
    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return slow;
    }
    return nullptr;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *meetingNode = hasCycle(head);
    if (meetingNode == nullptr)
        return nullptr;
    ListNode *slow = head, *fast = meetingNode;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    return 0;
}