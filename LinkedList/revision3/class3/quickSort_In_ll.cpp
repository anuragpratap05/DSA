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
    ListNode *prev = nullptr, *cur = head, *forw = cur->next;
    while (pivotIdx--)
    {
        prev = cur;
        cur = cur->next;
        forw = cur->next;
    }
    return {prev, cur, forw};
}

vector<ListNode *> segregate(ListNode *head, int pivotIdx)
{
    vector<ListNode *> vec = getPivotNode(head, pivotIdx);
    ListNode *prev = vec[0], *pNode = vec[1], *forw = vec[2], *cur = nullptr;

    ListNode *smallHd = new ListNode(-1);
    ListNode *small = smallHd;

    ListNode *largeHd = new ListNode(-1);
    ListNode *large = largeHd;

    if (prev == nullptr)
    {
        cur = pNode->next;
    }
    else
    {
        cur = head;
        prev->next = forw;
    }

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
    return {smallHd->next, pNode, largeHd->next};
}

vector<ListNode *> quickSortHelp(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return {head, head};
    }

    int llLength = linkedListLength(head);
    int mid = llLength / 2;

    vector<ListNode *> vec = segregate(head, mid);

    ListNode *lh = vec[0], *pNode = vec[1], *rh = vec[2];
    vector<ListNode *> left = quickSortHelp(lh);
    vector<ListNode *> right = quickSortHelp(rh);

    ListNode *h1 = left[0], *t1 = left[1], *h2 = right[0], *t2 = right[1];

    ListNode *nh = nullptr, *nt = nullptr;

    if (h1 == nullptr)
    {
        nh = pNode;
        pNode->next = h2;
        nt = t2;
    }
    else if (h2 == nullptr)
    {
        nh = h1;
        t1->next = pNode;
        nt = pNode;
    }
    else
    {
        nh = h1;
        t1->next = pNode;
        pNode->next = h2;
        nt = t2;
    }

    return {nh, nt};
}

ListNode *quickSort(ListNode *head)
{
    return quickSortHelp(head)[0];
}

int main()
{
    return 0;
}