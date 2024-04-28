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

int pivot(ListNode *head)
{
    int ans=0;
    while(head!=NULL)
    {
        ans= head->val;
        head=head->next;
         
    }

    return ans;
}

ListNode *segregateOnLastIndex(ListNode *head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }

    int data=pivot(head);

    ListNode* large = new ListNode(-1);
    ListNode* lp=large;
    ListNode* small = new ListNode(-1);
    ListNode* sp=small;

    ListNode* c=head;

    while(c!=nullptr)
    {
        if(c->val <= data)
        {
            sp->next=c;
            sp=c;
        }
        else{
            lp->next=c;
            lp=c;
        }
        c=c->next;
    }
    lp->next=sp->next=nullptr;

    sp->next=large->next;
    return sp;


}

int main()
{

return 0;
}