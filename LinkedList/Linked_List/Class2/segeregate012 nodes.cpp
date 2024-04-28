#include<bits/stdc++.h>
using namespace std;

// last me kon kiske next me judega is imp
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

ListNode *segregate012(ListNode *head)
{
    
    ListNode* zero=new ListNode(-1);
    ListNode* zp=zero;
    ListNode* one=new ListNode(-1);
    ListNode* op=one;
    ListNode* two=new ListNode(-1);
    ListNode* tp=two;

    ListNode* c=head;
    while(c!=nullptr)
    {
        if(c->val ==0)
        {
            zp->next=c;
            zp=c;
        }
        else if(c->val ==1)
        {
            op->next=c;
            op=c;
        }
        else
        {
            tp->next=c;
            tp=c;
        }
        c=c->next;
    }

    op->next=nullptr;
    zp->next=nullptr;
    tp->next=nullptr;
// order of line 52 and 53 matters;
    op->next= two->next;
    zp->next=one->next;
    return zero->next;

}


int main()
{

return 0;
}