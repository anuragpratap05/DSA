#include <bits/stdc++.h>
using namespace std;
// multiply two linked list kr lena
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
    if (l1 == nullptr or l2 == nullptr)
    {
        return (l1 == nullptr ? l2 : l1);
    }

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    int carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;

    while (c1 != nullptr or c2 != nullptr or carry > 0)
    {
        int sum = 0;
        if (c1 != nullptr)
        {
            sum += c1->val;
            c1 = c1->next;
        }
        if (c2 != nullptr)
        {
            sum += c2->val;
            c2 = c2->next;
        }

        sum += carry;
        carry = sum / 10;
        int v = sum % 10;
        ListNode *node = new ListNode(v);
        p->next = node;
        p = p->next;
    }
    return dummy->next;
}

int main()
{
    return 0;
}