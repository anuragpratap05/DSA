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

int getLength(ListNode *head)
{
    int curLen = 0;
    ListNode *c = head;
    while (c)
    {
        curLen++;
        c = c->next;
    }
    return curLen;
}

vector<ListNode *> segregate(ListNode *head, int pivotidx)
{
    ListNode *p = nullptr, *c = head;
    while (pivotidx--)
    {
        p = c;
        c = c->next;
    }

    ListNode *f = c->next;
    c->next = nullptr;
    ListNode *pn = c;
    if (p != nullptr)
    {
        p->next = f;
        c = head;
    }
    else
    {
        c = f;
    }

    ListNode *sh = new ListNode(-1), *sp = sh;
    ListNode *lh = new ListNode(-1), *lp = lh;

    while (c != nullptr)
    {
        if (c->val < pn->val)
        {
            sp->next = c;
            sp = c;
        }
        else
        {
            lp->next = c;
            lp = c;
        }
        c = c->next;
    }

    sp->next = lp->next = nullptr;
    return {sh->next, pn, lh->next};
}

vector<ListNode *> quickSortHelp(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return {head, head};

    int len = getLength(head);
    int mid = len / 2;
    vector<ListNode *> vec = segregate(head, mid);
    ListNode *lh = vec[0];
    ListNode *pn = vec[1];
    ListNode *rh = vec[2];

    vector<ListNode *> left = quickSortHelp(lh);
    vector<ListNode *> right = quickSortHelp(rh);

    ListNode *h1 = left[0], *t1 = left[1], *h2 = right[0], *t2 = right[1], *nh = NULL, *nt = NULL;

    if (h1 == nullptr)
    {
        nh = pn;
        pn->next = h2;
        nt = t2;
    }
    else if (h2 == nullptr)
    {
        nh = h1;
        t1->next = pn;
        nt = pn;
    }
    else
    {
        nh = h1;
        t1->next = pn;
        pn->next = h2;
        nt = t2;
    }
    return {nh, nt};
}

ListNode *sortList(ListNode *head)
{
    return quickSortHelp(head)[0];
}

int main()
{
    return 0;
}