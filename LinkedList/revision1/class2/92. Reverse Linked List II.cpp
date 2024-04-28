#include<bits/stdc++.h>
using namespace std;
using namespace std;
struct ListNode
{
    int data;
    struct ListNode* next;
    
    ListNode(int x){
        data = x;
        next = NULL;
    }
};
 ListNode* reverseList(ListNode* head) {
            if(head==nullptr or head->next==nullptr)
       {
           return head;
       } 

       ListNode* p=head,* c=head->next;
        p->next=nullptr;

       while(c!=NULL)
       {
           ListNode* f=c->next;
          // p->next=nullptr;
           c->next=p;
           
           p=c;
           c=f;
       }  
       return p;
    }

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* p=nullptr;

    ListNode* c1=head;
    ListNode* c2=head;

    while(--left)
    {
        p=c1;
        c1=c1->next;
    }
    ListNode* f=c2->next;

    while(--right)
    {
        
        c2=f;
        if(f!=nullptr)
        {
            f=f->next;
        }
    }
    c2->next=nullptr;
    ListNode* nh=reverseList(c1);
    c1->next=f;

    if(p!=nullptr)
    {
        p->next=nh;
    }
    if(p==nullptr)
    {
        return nh;
    }
    return head;

}

int main()
{
    return 0;
}