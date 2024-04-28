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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr or list2 == nullptr)
    {
        return (list1 == nullptr ? list2 : list1);
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;

    ListNode *c1 = list1;
    ListNode *c2 = list2;

    while (c1 != nullptr and c2 != nullptr)
    {
        if (c1->val < c2->val)
        {
            p->next = c1;
            p = p->next;

            c1 = c1->next;
        }
        else
        {
            p->next = c2;
            p = p->next;

            c2 = c2->next;
        }
    }
    if (c1 == nullptr)
    {
        p->next = c2;
    }
    else
    {
        p->next = c1;
    }
    return dummy->next;
}
ListNode *mergeKLists_help(vector<ListNode *> &lists, int s, int e)
{
    if (s == e)
    {
        return lists[s];
    }
    int mid = (s + e) / 2;
    ListNode *left = mergeKLists_help(lists, s, mid);
    ListNode *right = mergeKLists_help(lists, mid + 1, e);

    return mergeTwoLists(left, right);
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    return mergeKLists_help(lists, 0, n - 1);
}

int main()
{
    return 0;
}