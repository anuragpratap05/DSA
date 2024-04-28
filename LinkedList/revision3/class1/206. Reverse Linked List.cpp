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

int main()
{
    return 0;
}