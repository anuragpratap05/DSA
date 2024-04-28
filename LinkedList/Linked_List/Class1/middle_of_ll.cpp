#include<bits/stdc++.h>
using namespace std;

// use slow fast technique (handle null cases at last dry run on even and odd length ll)

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

ListNode *midNode(ListNode *head)
{
    if(head == NULL or head->next==NULL)
    {
        return head;
    }

    ListNode* slow= head;
    ListNode* fast=head;

    while(fast->next != NULL and fast->next->next != NULL)
    {
        fast=fast->next->next;
        slow = slow->next;
    }

    return slow;
    
}

int main()
{

}