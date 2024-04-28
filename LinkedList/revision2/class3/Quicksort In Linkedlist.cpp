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

int get_length(ListNode *head)
{
    int cnt = 0;
    ListNode *c = head;
    while (c != nullptr)
    {
        cnt++;
        c = c->next;
    }
    return cnt;
}

vector<ListNode *> pivotNode(ListNode *head, int pivotIdx)
{
    ListNode *c = head;
    ListNode *p = nullptr;
    ListNode *f = c->next;

    while (pivotIdx--)
    {
        p = c;
        c = c->next;
        f = c->next;
    }
    return {p, c, f};
}

vector<ListNode *> segregate(ListNode *head, int pivotIdx)
{
    if (head == nullptr or head->next == nullptr)
    {
        if (head == nullptr)
        {
            return {head, head, head};
        }
        else
        {
            return {head, head, nullptr};
        }
    }

    vector<ListNode *> vec = pivotNode(head, pivotIdx);
    ListNode *p = vec[0];
    ListNode *node = vec[1];
    ListNode *f = vec[2];
    ListNode *c = head;
    if (p == nullptr)
    {
        c = node->next;
        node->next = nullptr;
    }
    else
    {
        p->next = f;
        node->next = nullptr;
    }

    ListNode *larger = new ListNode(-1);
    ListNode *l = larger;

    ListNode *smaller = new ListNode(-1);
    ListNode *s = smaller;

    while (c != nullptr)
    {
        if (c->val <= node->val)
        {
            s->next = c;
            s = c;
        }
        else
        {
            l->next = c;
            l = c;
        }
        c = c->next;
    }

    s->next = l->next = nullptr;
    // node->next = larger->next;
    // s->next = node;
    return {smaller->next, node, larger->next};
}

vector<ListNode *> quickSort_help(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return {head, head};
    }

    int len = get_length(head);
    int pivot_idx = len / 2;

    vector<ListNode *> vec = segregate(head, pivot_idx);
    ListNode *lh = vec[0];
    ListNode *node = vec[1];
    ListNode *rh = vec[2];

    vector<ListNode *> left = quickSort_help(lh);
    vector<ListNode *> right = quickSort_help(rh);

    ListNode *h1 = left[0];
    ListNode *t1 = left[1];

    ListNode *h2 = right[0];
    ListNode *t2 = right[1];

    ListNode *oh;
    ListNode *ot;
    if (h2 == nullptr)
    {
        ot = node;
    }
    else
    {
        node->next = h2;

        ot = t2;
    }

    if (t1 == nullptr)
    {
        oh = node;
    }
    else
    {
        t1->next = node;
        oh = h1;
    }

    return {oh, ot};
}

ListNode *quickSort(ListNode *head)
{
    return quickSort_help(head)[0];
}

int main()
{
    return 0;
}