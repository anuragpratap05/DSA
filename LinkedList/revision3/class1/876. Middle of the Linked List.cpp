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

int main()
{
    return 0;
}