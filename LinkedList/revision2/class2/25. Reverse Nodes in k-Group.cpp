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
int len(ListNode *head)
{
    int cnt = 0;
    ListNode *c = head;
    while (c != nullptr)
    {
        c = c->next;
        cnt++;
    }
    return cnt;
}
ListNode *oh = nullptr;
ListNode *ot = nullptr;
ListNode *th = nullptr;
ListNode *tt = nullptr;

void addfirst(ListNode *node)
{
    if (th == nullptr and tt == nullptr)
    {
        th = tt = node;
        return;
    }
    node->next = th;
    th = node;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    int length = len(head);
    int val = length / k;
    ListNode *c = head;
    ListNode *f;
    while (val--)
    {
        int tempk = k;
        th = nullptr;
        tt = nullptr;
        while (tempk--)
        {
            f = c->next;
            c->next = nullptr;
            addfirst(c);
            c = f;
        }
        if (oh == nullptr and ot == nullptr)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }
    }
    ot->next = f;
    return oh;
}

int main()
{
    return 0;
}