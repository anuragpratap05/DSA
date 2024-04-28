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
bool isPalindrome(Node* head)
{
    Node* mid=middleNode(head);
    Node* nh=mid->next;
    mid->next=nullptr;
    nh=reverseList(nh);

    Node* c1=head;
    Node* c2=nh;

    while(c1!=nullptr and c2!=nullptr)
    {
        if(c1->val!=c2->val)
        {
            return false;
        }
        c1=c1->next;
        c2=c2->next;
    }
    return true;
}

int main()
{
    return 0;
}