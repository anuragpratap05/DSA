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

vector<ListNode *> findval(ListNode *head)
{
    ListNode *c = head;
    ListNode *p = nullptr;
    while (c->next != nullptr)
    {
        p = c;
        c = c->next;
    }
    return {p, c};
}

ListNode *segregateOnLastIndex(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }
    vector<ListNode *> vec = findval(head);
    // ListNode *p = vec[0];
    ListNode *node = vec[1];
    // p->next = nullptr;
    ListNode *smaller = new ListNode(-1);
    ListNode *s = smaller;
    ListNode *larger = new ListNode(-1);
    ListNode *l = larger;

    ListNode *c = head;
    while (c != nullptr)
    {
        if (c->val <= node->val)
        {
            s->next = c;
            s = s->next;
        }
        else
        {
            l->next = c;
            l = l->next;
        }
        c = c->next;
    }
    s->next = nullptr;
    l->next = nullptr;
    s->next = larger->next;

    return s;
}

int main()
{
    return 0;
}