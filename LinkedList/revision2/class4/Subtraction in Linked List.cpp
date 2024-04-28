
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

int get_length(Node *head)
{
    int cnt = 0;
    Node *c = head;
    while (c != nullptr)
    {
        cnt++;
        c = c->next;
    }
    return cnt;
}

bool is_first_list_greater(Node *l1, Node *l2)
{
    Node *c1 = l1;
    Node *c2 = l2;
    while (c1 != nullptr)
    {
        if (c1->data == c2->data)
        {
            c1 = c1->next;
            c2 = c2->next;
        }
        else if (c1->data > c2->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // yha aya mtlb both lists are equal;
    return false;
}

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

Node *subLinkedList(Node *l1, Node *l2)
{
    while (l1->data == 0)
    {
        l1 = l1->next;
        if (l1 == nullptr)
        {
            break;
        }
    }
    while (l2->data == 0)
    {
        l2 = l2->next;
        if (l2 == nullptr)
        {
            break;
        }
    }
    Node *b;
    Node *s;
    int fst_len = get_length(l1);
    int scd_len = get_length(l2);

    if (fst_len > scd_len)
    {
        // cout<<"fist is grtr";
        b = l1;
        s = l2;
    }
    else if (fst_len < scd_len)
    {
        // cout<<"scnd i sgrtr";
        b = l2;
        s = l1;
    }
    else
    {
        if (is_first_list_greater(l1, l2))
        {
            b = l1;
            s = l2;
        }
        else
        {
            b = l2;
            s = l1;
        }
    }

    b = reverseList(b);
    s = reverseList(s);

    Node *c1 = b;
    Node *c2 = s;
    int carry = 0;
    Node *dummy = new Node(-1);
    Node *p = dummy;
    while (c1 != nullptr)
    {
        int a = c1->data;
        int b = (c2 == nullptr ? 0 : c2->data);
        a += carry;
        if (a < b)
        {
            a += 10;
            carry = -1;
        }
        else
        {
            carry = 0;
        }
        int val = a - b;
        Node *node = new Node(val);
        p->next = node;
        p = p->next;
        c1 = c1->next;
        if (c2 != nullptr)
        {
            c2 = c2->next;
        }
    }
    Node *rh = reverseList(dummy->next);
    while (rh != nullptr)
    {
        if (rh->data != 0)
        {
            return rh;
        }
        rh = rh->next;
    }
    if (rh == nullptr)
    {
        return new Node(0);
    }
}