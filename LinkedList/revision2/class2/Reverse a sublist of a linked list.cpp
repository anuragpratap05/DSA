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
Node *reverseList(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    Node *p = nullptr;
    Node *c = head;

    while (c != nullptr)
    {
        Node *f = c->next;
        c->next = p;
        p = c;
        c = f;
    }
    return p;
}
Node *reverseBetween(Node *head, int m, int n)
{
    Node *t1 = nullptr;

    Node *dummy = new Node(-1);

    dummy->next = head;
    Node *c = dummy;

    int cnt = 0;
    Node *nh;
    Node *f1;
    while (cnt != n)
    {
        if (cnt == m - 1)
        {
            t1 = c;
            nh = c->next;
        }

        cnt++;
        c = c->next;
    }

    t1->next = nullptr;
    f1 = c->next;

    c->next = nullptr;

    Node *x = reverseList(nh);
    t1->next = x;
    nh->next = f1;
    return dummy->next;
}

int main()
{
    return 0;
}