#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *segregate(Node *head)
{
    Node *zero = new Node(-1);
    Node *z = zero;
    Node *one = new Node(-1);
    Node *o = one;
    Node *two = new Node(-1);
    Node *t = two;

    Node *c = head;
    while (c != nullptr)
    {
        if (c->data == 0)
        {
            z->next = c;
            z = c;
        }
        else if (c->data == 1)
        {
            o->next = c;
            o = c;
        }
        else
        {
            t->next = c;
            t = c;
        }
        c = c->next;
    }
    z->next = nullptr;
    o->next = nullptr;
    t->next = nullptr;

    o->next = two->next;
    z->next = one->next;
    return zero->next;
}

int main()
{
    return 0;
}