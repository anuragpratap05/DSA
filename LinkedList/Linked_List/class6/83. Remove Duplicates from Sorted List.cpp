#include<bits/stdc++.h>
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
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }
    ListNode* dummy=new ListNode(-1000);
    ListNode* p=dummy;
    ListNode* c=head;

    while(c!=NULL)
    {
        if(c->val!=p->val)
        {
            p->next=c;
        }
        c=c->next;
        
    }
    return dummy->next;
    
}

int main()
{
    return 0;
}