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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    int tempLeft = left - 1;

    ListNode *prev = nullptr;

    ListNode *leftNd, *rightNd = head;

    while (tempLeft--)
    {
        prev = leftNd;
        leftNd = leftNd->next;
        rightNd = rightNd->next;
    }
    if (prev != nullptr)
        prev->next = nullptr;

    int midGap = right - left;

    while (midGap--)
    {
        rightNd = rightNd->next;
    }
    ListNode *forw = rightNd->next;
    rightNd->next = nullptr;

    pair<ListNode *, ListNode *> p = reverseList(leftNd);

    if (prev != nullptr)
        prev->next = p.first;
    p.second->next = forw;

    return prev == nullptr ? p.first : head;
}

int main()
{
    return 0;
}