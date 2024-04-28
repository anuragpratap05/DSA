#include<bits/stdc++.h>
using namespace std;
// gfg solution
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
int length(Node* head)
{
   int c=0;
   while(head!=nullptr)
   {
       
        c++;
       head=head->next;
       
   } 
   return c;
}
int getsum(Node* head)
{
    int sum=0;
    while(head!=nullptr)
    {
        sum=sum*10+head->data;
        cout<<sum<<endl;
        head=head->next;
    }
    return sum;

}
 bool isl1greater(Node* l1, Node* l2)
    {
        while(l1!=nullptr)
        {
            if(l1->data==l2->data)
            {
                l1=l1->next;
                l2=l2->next;
            }
            if(l1->data > l2->data)
            {
                return true;
            }
            else
            {
               return false; 
            }
            
        }
        return false;
    }


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
    
Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1->data==0)
    {
        l1=l1->next;
        if(l1==nullptr)
        {
            break;
        }
    }
    while(l2->data==0)
    {
        l2=l2->next;
        if(l2==nullptr)
        {
            break;
        }
    }
   
    
    Node* c1;
    Node* c2;
    Node* dummy=new Node(-1);
    Node* p=dummy;

    int lenofl1=length(l1);
    int lenofl2=length(l2);
    
   // cout<<lenofl1<<"  "<<lenofl2<<endl;



    if(lenofl1>lenofl2)
    {
        c1=l1;
        c2=l2;
    }
    else if(lenofl2>lenofl1)
    {
        c1=l2;
        c2=l1;
    }
    else{
     
        bool ans=isl1greater(l1,l2);
       
        if(ans)
        {
           c1=l1;
            c2=l2; 
        }
        else{
            c1=l2;
            c2=l1;
        }
    }
    c1=reverseList(c1);
    c2=reverseList(c2);

    int borrow=0;
    while(c1!=nullptr)
    {
        int a=c1->data;
        a-=borrow;
        int b= (c2!=nullptr?c2->data:0);
        
        if(a<b)
        {
            a+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        int val=a-b;
        p->next=new Node(val);
        p=p->next;
        c1=c1->next;
        if(c2!=nullptr)
        {
            c2=c2->next;
        }


    }
    Node* nh=reverseList(dummy->next);
    while(nh->data==0)
    {
        nh=nh->next;
        if(nh==nullptr)
        {
            return new Node(0);
        }
    }
    return nh;
    
}

int main()
{
    return 0;
}