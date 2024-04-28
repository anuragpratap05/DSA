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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *c = head, *p = nullptr, *oh = nullptr, *ot = nullptr;
    while (c)
    {
        int tempk = k;
        ListNode *tempHd = c;
        int curChunkSize = 0;
        while (c and tempk--)
        {
            p = c;
            c = c->next;
            curChunkSize++;
        }
        p->next = nullptr;
        if (curChunkSize < k)
        {
            ot->next = tempHd;
        }
        else
        {
            ListNode *reversedHd = reverseList(tempHd);
            if (oh == nullptr and ot == nullptr)
            {
                oh = reversedHd;
                ot = tempHd;
            }
            else
            {
                ot->next = reversedHd;
                ot = tempHd;
            }
        }
    }
    return oh;
}

int main()
{
    return 0;
}