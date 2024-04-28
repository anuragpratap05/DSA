#include<bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data = 0;
    ListNode *next = nullptr;

    ListNode(int data)
    {
        this->data = data;
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
void unfold(ListNode *head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return ;
    }

    ListNode* c1=head;
    ListNode* c2=head->next;
    ListNode* nh=c2;
    while((c1->next!=nullptr and c1->next->next!=nullptr) or (c2!=nullptr and c2->next!=nullptr and c2->next->next!=nullptr))
    {
        c1->next=c1->next->next;
        c1=c1->next;
        c2->next=c2->next->next;
        c2=c2->next;
    }

    // ye if condition nhi likhoge tb bhi chlega code:
    if(c2!=nullptr)
    {
        c1->next=nullptr;
    }

    nh=reverseList(nh);
    c1->next=nh;
}


int main()
{
    return 0;
}