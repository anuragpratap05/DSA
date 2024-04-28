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

void All_variables(ListNode* head)
{
    ListNode* meeting=isCyclePresentInLL(head);
    if(meeting==nullptr or meeting->next==nullptr)
    {
        // mtlb cycle hai hi nhi ll me dono LL spat(plain) hai
        //return nullptr;
    }

    ListNode* f=meeting, *s=head;
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

    s=meeting;
    s=s->next;
    int cyclelen=1;
    while(s!=meeting)
    {
        s=s->next;
        cyclelen++;
    }
    int c=A-(Mdash* cyclelen);
    int b=cyclelen-c;
    int m=Mdash+1;


}


int main()
{
    return 0;
}