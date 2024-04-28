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
Node *divide(int N, Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }
    Node *edummy = new Node(-1);
    Node *e = edummy;
    Node *odummy = new Node(-1);
    Node *o = odummy;

    Node *c = head;
    while (c != nullptr)
    {
        if (c->data % 2 == 0)
        {
            e->next = c;
            c = c->next;
        }
        else
        {
            o->next = c;
            c = c->next;
        }
    }
    e->next = nullptr;
    o->next = nullptr;
    e->next = odummy->next;
    return edummy->next;
}

int main()
{
    return 0;
}