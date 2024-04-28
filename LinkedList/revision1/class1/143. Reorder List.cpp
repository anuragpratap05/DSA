#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val = 0;
    Node *next = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};
Node* reverseList(Node* head) {
            if(head==nullptr or head->next==nullptr)
       {
           return head;
       } 

       Node* p=head,* c=head->next;
        p->next=nullptr;

       while(c!=NULL)
       {
           Node* f=c->next;
          // p->next=nullptr;
           c->next=p;
           
           p=c;
           c=f;
       }  
       return p;
    }
Node* middleNode(Node* head)
{
    Node* slow=head,*fast=head;
    while(fast->next!=nullptr and fast->next->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;


}

void reorderList(Node* head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return ;
    }
    Node* mid=middleNode(head);
    Node* nh=mid->next;
    mid->next=nullptr;
    nh=reverseList(nh);

    Node* c1=head;
    Node* c2=nh;
    Node* p=c1->next;
    Node* q=c2->next;

    while(p!=nullptr and q!=nullptr)
    {
        c1->next=c2;
        c2->next=p;
        
        c1=p;
        c2=q;
        p=p->next;
        q=q->next;
    }
    c1->next=c2;
    c2->next=p;
    if(p!=nullptr)
    {
        p->next=nullptr;
    }






}

int main()
{
    return 0;
}