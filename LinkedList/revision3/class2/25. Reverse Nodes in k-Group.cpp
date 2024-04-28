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

pair<ListNode *, ListNode *> reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return {head, head};

    ListNode *prev = nullptr, *curr = head, *forw = head->next;

    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = forw;
        if (forw != nullptr)
            forw = forw->next;
    }
    return {prev, head};
}
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

ListNode *reverseKGroup2(ListNode *head, int k)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    int tempK = k - 1;
    int llLength = linkedListLength(head);

    ListNode *curr = head;
    while (tempK--)
    {
        curr = curr->next;
    }
    ListNode *f = curr->next;
    curr->next = nullptr;
    curr = f;

    pair<ListNode *, ListNode *> p = reverseList(head);
    ListNode *oHead = p.first;
    ListNode *prev = p.second;
    int processedChunk = 1;
    while (curr != nullptr)
    {
        int remNodes = llLength - (processedChunk * k);
        if (remNodes >= k)
        {
            tempK = k;
            ListNode *curPrev = nullptr;
            ListNode *tempHd = curr;
            while (tempK--)
            {
                curPrev = curr;
                curr = curr->next;
            }
            curPrev->next = nullptr;
            pair<ListNode *, ListNode *> p = reverseList(tempHd);
            prev->next = p.first;
            prev = p.second;
            processedChunk++;
        }
        else
        {
            prev->next = curr;
            break;
        }
    }
    return oHead;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    int llLength = linkedListLength(head);

    ListNode *oh = nullptr, *ot = nullptr, *curPrev = nullptr, *cur = head;
    int processedChunk = 0;
    while (cur != nullptr)
    {
        int remNodes = llLength - (processedChunk * k);
        if (remNodes < k)
            break;
        int tempK = k;
        ListNode *tempHd = cur;
        while (tempK--)
        {
            curPrev = cur;
            cur = cur->next;
        }
        curPrev->next = nullptr;
        pair<ListNode *, ListNode *> p = reverseList(tempHd);
        if (oh == nullptr)
        {
            oh = p.first;
            ot = p.second;
        }
        else
        {
            ot->next = p.first;
            ot = p.second;
        }
        processedChunk++;
    }
    ot->next = cur;
    return oh;
}

int main()
{
    return 0;
}