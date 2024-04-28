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
    map<Node *, Node *> m;
    map<Node *, Node *> rand;
    Node *c = head;
    Node *dummy = new Node(-1);
    Node *p = dummy;
    while (c != nullptr)
    {
        int value = c->val;
        Node *x = new Node(value);
        m[c] = x;
        rand[c] = c->random;
        p->next = x;
        p = p->next;
        c = c->next;
    }
    for (auto i : rand)
    {
        Node *p1 = m[i.first];
        if (rand[i.first] == nullptr)
        {
            p1->random = nullptr;
        }
        else
        {
            p1->random = m[i.second];
        }
    }
    return dummy->next;
}

Node *copyRandomListWithoutSpace(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        if (head == nullptr)
        {
            return head;
        }
        Node *x = new Node(head->val);
        if (head->random != nullptr)
        {
            x->random = x;
        }
        return x;
    }
    Node *c = head;
    while (c != nullptr)
    {
        Node *f = c->next;
        Node *x = new Node(c->val);
        c->next = x;
        x->next = f;
        c = f;
    }
    Node *c1 = head;
    Node *c2 = head->next;
    Node *nh = c2;
    while (c1 != nullptr)
    {
        Node *f1 = c1->next->next;
        Node *f2;
        if (c2->next != nullptr)
        {
            f2 = c2->next->next;
        }
        else
        {
            f2 = f2->next;
        }
        c2->random = (c1->random == nullptr ? nullptr : c1->random->next);

        c1 = f1;
        c2 = f2;
    }
    c1 = head;
    c2 = head->next;
    while (c2->next != nullptr)
    {
        c1->next = c1->next->next;
        c2->next = c2->next->next;
        c1 = c1->next;
        c2 = c2->next;
    }
    c1->next = nullptr;
    return nh;
}
int main()
{
    return 0;
}