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
    {
        return head;
    }
    ListNode *curr = head;
    ListNode *s = curr;
    ListNode *f = curr;
    while (f != nullptr and f->next != nullptr)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}
// 1st mid
ListNode *midNode(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode *s = head;
    ListNode *f = head;

    while (f->next != nullptr and f->next->next != nullptr)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

int main()
{
    return 0;
}