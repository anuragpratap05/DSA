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
// recursive method:
ListNode* final=nullptr;
     ListNode* reverseList_rec(ListNode* head) {

    ListNode* c=head;

    if(head->next==nullptr)
    {
        final=head;
        return head;

    }
    ListNode* nh=reverseList_rec(head->next);
    nh->next=head;
    head->next=nullptr;
    return head;


        
    }
    ListNode* reverseList01(ListNode* head) {
        if(head==nullptr or head->next==nullptr)
        {
            return head;
        }
        reverseList_rec(head);
        return final;
    }
// iterative method:
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

int main()
{
    return 0;
}