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
    ListNode *p = nullptr, *c = head;
    while (c != nullptr)
    {
        ListNode *f = c->next;
        c->next = p;
        p = c;
        c = f;
    }
    return p;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    left -= 1, right -= 1;
    ListNode *c = head, *p = nullptr;
    while (right)
    {
        if (left)
        {
            p = c;
            left--;
        }
        right--;
        c = c->next;
    }
    ListNode *f = c->next;
    c->next = nullptr;

    ListNode *tempH = p == nullptr ? head : p->next;

    ListNode *reversedHd = reverseList(tempH);
    tempH->next = f;

    if (p == nullptr)
        return reversedHd;
    p->next = reversedHd;
    return head;
}

int main()
{
    return 0;
}