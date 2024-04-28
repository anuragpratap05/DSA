#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *multiplySingleDigit(Node *head, int digit)
{
    if (digit == 0 or digit == 1)
        return digit == 0 ? new Node(0) : head;
    Node *cur = head;
    int carry = 0;
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (cur != nullptr or carry > 0)
    {
        int val = cur != nullptr ? cur->data : 0;
        int prod = (val * digit) + carry;
        int ndVal = prod % 10;
        carry = prod / 10;
        Node *node = new Node(ndVal);
        prev->next = node;
        prev = node;
        if (cur != nullptr)
            cur = cur->next;
    }
    return dummy->next;
}

Node *addPrefixZeroes(Node *head, int cnt)
{
    if (cnt == 0)
        return head;

    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (cnt--)
    {
        Node *node = new Node(0);
        prev->next = node;
        prev = node;
    }
    prev->next = head;
    return dummy->next;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    if (l1 == nullptr or l2 == nullptr)
        return l1 == nullptr ? l2 : l1;
    Node *c1 = l1;
    Node *c2 = l2;
    int carry = 0;
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (c1 != nullptr or c2 != nullptr or carry > 0)
    {
        int val1 = c1 != nullptr ? c1->data : 0;
        int val2 = c2 != nullptr ? c2->data : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int ndval = sum % 10;
        Node *node = new Node(ndval);
        prev->next = node;
        prev = prev->next;
        if (c1 != nullptr)
            c1 = c1->next;
        if (c2 != nullptr)
            c2 = c2->next;
    }
    return dummy->next;
}

Node *reverseList(Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *prev = nullptr, *curr = head, *forw = head->next;

    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = forw;
        if (forw != nullptr)
            forw = forw->next;
    }
    return prev;
}

long long getValFromListNodes(Node *head)
{
    Node *cur = head;

    while (cur != nullptr and cur->data == 0)
        cur = cur->next;

    if (cur == nullptr)
        return 0;

    long long sum = 0;
    while (cur != nullptr)
    {
        sum = sum * 10 + cur->data;
        sum %= 1000000007;
        cur = cur->next;
    }
    return sum;
}

long long multiplyTwoLists(Node *l1, Node *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node *cur = l2, *prevList = nullptr;
    int zeroCnt = 0;
    while (cur != nullptr)
    {
        Node *prodList = multiplySingleDigit(l1, cur->data);
        prodList = addPrefixZeroes(prodList, zeroCnt);
        Node *curList = addTwoNumbers(prevList, prodList);

        prevList = curList;
        zeroCnt++;
        cur = cur->next;
    }
    prevList = reverseList(prevList);
    return getValFromListNodes(prevList);
}

int main()
{
    return 0;
}