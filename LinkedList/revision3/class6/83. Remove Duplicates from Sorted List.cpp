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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *c = head, *f = head->next;

    while (c != nullptr)
    {
        while (f != nullptr and f->val == c->val)
        {
            f = f->next;
        }
        c->next = f;
        c = f;
    }
    return head;
}

int main()
{
    return 0;
}