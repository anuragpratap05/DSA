#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    
    ListNode(int x){
        val = x;
        next = NULL;
    }
    
};
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return nullptr;
    }
    ListNode* dummy=new ListNode(-1);
    ListNode* p=dummy;
    ListNode* c=head;
    ListNode* f=c->next;

    while(f!=nullptr)
    {
        if(c->val==f->val)
        {
            int data=c->val;
            while(c->val==data and c!=nullptr)
            {
                c=c->next;
                if(f!=nullptr)
                {
                    f=f->next;
                }
            }
            if( f==nullptr)
            {
                p->next=c;
                p=c;
                return dummy->next;
            }
            else{
                continue;
            }

        }
        else{
            p->next=c;
            p=c;
            c=f;
            if(f!=nullptr)
                {
                    f=f->next;
                }
        }
    }
    return dummy->next;
}

int main()
{
    return 0;
}