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

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *oddhd = head;
    ListNode *oddP = head;

    ListNode *evenhd = head->next;
    ListNode *evenP = head->next;

    ListNode *oddPrev = nullptr;

    while (evenP != nullptr and oddP != nullptr)
    {
        oddPrev = oddP;
        oddP->next = evenP->next;
        oddP = oddP->next;

        if (oddP != nullptr)
        {
            evenP->next = oddP->next;
            evenP = evenP->next;
        }
    }
    if (evenP == nullptr)
        oddP->next = evenhd;
    else
        oddPrev->next = evenhd;
    return head;
}

int main()
{
    return 0;
}