#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return head;

    Node *c = head;
    while (c)
    {
        Node *f = c->next;
        Node *nd = new Node(c->val);
        c->next = nd;
        nd->next = f;
        c = f;
    }

    c = head;
    while (c)
    {
        c->next->random = c->random == nullptr ? nullptr : c->random->next;
        c = c->next->next;
    }

    Node *c1 = head;
    Node *c2 = head->next;
    Node *nh = c2;

    while (c1 and c2)
    {
        Node *f1 = c1->next->next;
        Node *f2 = c2->next == nullptr ? c2->next : c2->next->next;

        c1->next = f1;
        c1 = f1;
        c2->next = f2;
        c2 = f2;
    }
    return head;
}

int main()
{
    return 0;
}