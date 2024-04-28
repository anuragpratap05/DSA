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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int tempN = n - 1;
    ListNode *slow = head, *fast = head, *prev = nullptr;

    while (tempN--)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev == nullptr)
        return slow->next;
    prev->next = slow->next;
    return head;
}

int main()
{
    return 0;
}