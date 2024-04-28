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

int linkedListLength(ListNode *head)
{
    if (head == nullptr)
        return 0;

    ListNode *curr = head;
    int cnt = 0;
    while (curr != nullptr)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}
vector<ListNode *> getPivotNode(ListNode *head, int pivotIdx)
{
    pivotIdx--;
    ListNode *prev = nullptr, *cur = head, *forw = cur->next;
    while (pivotIdx--)
    {
        prev = cur;
        cur = cur->next;
        forw = cur->next;
    }
    return {prev, cur, forw};
}

ListNode *segregate(ListNode *head, int pivotIdx)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    vector<ListNode *> vec = getPivotNode(head, pivotIdx);
    ListNode *prev = vec[0], *pNode = vec[1], *forw = vec[2], *cur = head;

    ListNode *smallHd = new ListNode(-1);
    ListNode *small = smallHd;

    ListNode *largeHd = new ListNode(-1);
    ListNode *large = largeHd;

    prev == nullptr ? cur = pNode->next : prev->next = forw;
    pNode->next = nullptr;

    while (cur != nullptr)
    {
        if (cur->val < pNode->val)
        {
            small->next = cur;
            small = small->next;
        }
        else
        {
            large->next = cur;
            large = large->next;
        }
        cur = cur->next;
    }

    small->next = large->next = nullptr;
    pNode->next = largeHd->next;
    small->next = pNode;
    return smallHd->next;
}

int main()
{
    return 0;
}