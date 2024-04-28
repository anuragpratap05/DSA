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

void createNewNode(ListNode *&curr, ListNode *&prev)
{
    ListNode *newNode = new ListNode(curr->val);
    prev->next = newNode;
    prev = newNode;
    curr = curr->next;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    ListNode *c1 = list1, *c2 = list2;

    while (c1 != nullptr and c2 != nullptr)
    {
        if (c1->val < c2->val)
            createNewNode(c1, prev);
        else
            createNewNode(c2, prev);
    }

    while (c1 != nullptr)
        createNewNode(c1, prev);

    while (c2 != nullptr)
        createNewNode(c2, prev);

    return dummy->next;
}

int main()
{
    return 0;
}