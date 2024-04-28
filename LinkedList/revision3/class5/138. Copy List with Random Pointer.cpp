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
        return nullptr;

    Node *cur = head;
    while (cur != nullptr)
    {
        Node *forw = cur->next;
        Node *node = new Node(cur->val);
        cur->next = node;
        node->next = forw;
        cur = forw;
    }

    Node *c1 = head;
    Node *c2 = head->next;
    Node *nh = c2;
    while (c1 != nullptr and c2 != nullptr)
    {
        Node *f1 = c1->next->next;
        Node *f2 = c2->next != nullptr ? c2->next->next : nullptr;
        c2->random = c1->random->next;
        c2->random = c1->random == nullptr ? nullptr : c1->random->next;
        c1 = f1;
        c2 = f2;
    }

    c1 = head;
    c2 = head->next;

    while (c1 != nullptr)
    {
        c1->next = c1->next->next;
        c1 = c1->next;
        c2->next = c2->next == nullptr ? nullptr : c2->next->next;
        c2 = c2->next;
    }

    return nh;
}

int main()
{
    return 0;
}