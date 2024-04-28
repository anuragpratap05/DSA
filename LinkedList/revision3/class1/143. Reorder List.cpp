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

ListNode *middleNode(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *slow = head, *fast = head;

    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *prev = nullptr, *curr = head, *forw = head->next;

    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = forw;
        if (forw != nullptr)
            forw = forw->next;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return;

    ListNode *midNode = middleNode(head);

    ListNode *c2 = midNode->next;
    midNode->next = nullptr;
    ListNode *c1 = head;
    c2 = reverseList(c2);

    while (c1 != nullptr and c2 != nullptr)
    {
        ListNode *f1 = c1->next;
        ListNode *f2 = c2->next;

        c1->next = c2;
        c2->next = f1;
        c1 = f1;
        c2 = f2;
    }
}

int main()
{
    return 0;
}