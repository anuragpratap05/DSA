#include<bits/stdc++.h>
using namespace std;
class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// for leetcode

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* c1=l1;
    ListNode* c2=l2;
    ListNode* dummy=new ListNode(-1);
    ListNode* p=dummy;


    int carry=0;
    while(c1!=nullptr or c2!=nullptr or carry!=0)
    {
        int a= (c1==nullptr?0:c1->val);
        int b= (c2==nullptr?0:c2->val);

        int val=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        p->next= new ListNode(val);
        p=p->next;
        if(c1!=nullptr)
        {
            c1=c1->next;
        }
        if(c2!=nullptr)
        {
            c2=c2->next;
        }
    }
    return dummy->next;


}

// for gfg
 struct Node* reverseList(struct Node* head) {
            if(head==nullptr or head->next==nullptr)
       {
           return head;
       } 

       struct Node* p=head,* c=head->next;
        p->next=nullptr;

       while(c!=NULL)
       {
           struct Node* f=c->next;
          // p->next=nullptr;
           c->next=p;
           
           p=c;
           c=f;
       }  
       return p;
    }
struct Node* addTwoLists(struct Node* l1, struct Node* l2)
{
    l1=reverseList(l1);
    l2=reverseList(l2);
    
    struct Node* c1=l1;
    struct Node* c2=l2;
    struct Node* dummy=nullptr;
    struct Node* p=dummy;


    int carry=0;
    while(c1!=nullptr or c2!=nullptr or carry!=0)
    {
        int a= (c1==nullptr?0:c1->val);
        int b= (c2==nullptr?0:c2->val);

        int val=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        p->next= new struct Node(val);
        p=p->next;
        if(c1!=nullptr)
        {
            c1=c1->next;
        }
        if(c2!=nullptr)
        {
            c2=c2->next;
        }
    }
    return reverseList(dummy->next);
}

int main()
{
    return 0;
}