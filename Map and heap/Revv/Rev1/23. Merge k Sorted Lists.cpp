#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr or list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

    ListNode *c1 = list1, *c2 = list2, *dummy = new ListNode(-1), *prev = dummy;

    while (c1 and c2)
    {
        if (c1->val < c2->val)
        {
            prev->next = c1;
            prev = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            prev = c2;
            c2 = c2->next;
        }
    }
    prev->next = c1 == nullptr ? c2 : c1;
    return dummy->next;
}

ListNode *mergeKListsHelper(vector<ListNode *> &lists, int s, int e)
{
    if (s > e)
        return nullptr;
    
    if (s == e)
        return lists[s];
    

    int mid = (s + e) / 2;

    ListNode *leftSortedhd = mergeKListsHelper(lists, 0, mid);
    ListNode *rightSortedhd = mergeKListsHelper(lists, mid + 1, e);
    return mergeTwoLists(leftSortedhd, rightSortedhd);
}


ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return mergeKListsHelper(lists, 0, lists.size() - 1);
}

int main()
{
    return 0;
}