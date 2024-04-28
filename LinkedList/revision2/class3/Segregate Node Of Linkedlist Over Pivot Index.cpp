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

ListNode *segregate(ListNode *head, int pivotIdx)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
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
    node->next = larger->next;
    s->next = node;
    return smaller->next;
}

int main()
{
    return 0;
}