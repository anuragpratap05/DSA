#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *c1 = l1;
    ListNode *c2 = l2;
    int carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (c1 != nullptr or c2 != nullptr or carry > 0)
    {
        int val1 = c1 != nullptr ? c1->val : 0;
        int val2 = c2 != nullptr ? c2->val : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int ndval = sum % 10;
        ListNode *node = new ListNode(ndval);
        prev->next = node;
        prev = prev->next;
        if (c1 != nullptr)
            c1 = c1->next;
        if (c2 != nullptr)
            c2 = c2->next;
    }
    return dummy->next;
}

int main()
{
    return 0;
}