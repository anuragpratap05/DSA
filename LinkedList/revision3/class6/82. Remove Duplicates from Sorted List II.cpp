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

    ListNode *prev = nullptr, *cur = head, *forw = head, *nHead = nullptr;
    while (cur != nullptr)
    {
        bool loopRan = false;
        forw = forw->next;
        while (forw != nullptr and cur->val == forw->val)
        {
            loopRan = true;
            forw = forw->next;
        }
        if (!loopRan)
        {
            if (prev != nullptr)
                prev->next = cur;
            prev = cur;
            if (nHead == nullptr)
                nHead = prev;
        }
        cur = forw;
    }
    if (prev != nullptr)
        prev->next = nullptr;
    return nHead;
}

int main()
{
    return 0;
}