#include<bits/stdc++.h>
using namespace std;

// found intersection of LL using floyd warshall method
// pehli LL ka tail find kro phir tail ko dusri LL ke head se join krdo
//phir vo node find krlo jha se cycle start hui ho

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
 
class Solution {
public:
    ListNode* isCyclePresentInLL(ListNode *head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return nullptr;
    }
    ListNode* s=head;
    ListNode* f=head;

    while(f != nullptr and f->next != nullptr)
    {
        f=f->next->next;
        s=s->next;
        if(s==f)
        {
            return f;
        }
    }
    return f;  
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    //     if(headA== nullptr or headA->next== nullptr or headB==nullptr or headB->next==nullptr)
    // {
    //     return nullptr;
    // }
    ListNode* c=headA;
    while(c->next!=nullptr)
    {
        c=c->next;
    }
    c->next=headB;

    ListNode* meeting=isCyclePresentInLL(headA);
    if(meeting==nullptr or meeting->next==nullptr)
    {
        c->next=NULL;
        return nullptr;
    }

    ListNode* f=meeting, *s=headA;
    int A=0;
    int Mdash=0;

    while(s!=f)
    {   
        s=s->next;
        f=f->next;

        if(f==meeting)
        {
            Mdash++;
        }
        A++;
        
    }
        c->next=NULL;
    return s;
        
    }
};

int main()
{
    return 0;
}