#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* c1=l1;
    Node* c2=l2;
    Node* dummy=new Node(-1);
    Node* p=dummy;


    int carry=0;
    while(c1!=nullptr or c2!=nullptr or carry!=0)
    {
        int a= (c1==nullptr?0:c1->data);
        int b= (c2==nullptr?0:c2->data);

        int val=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        p->next= new Node(val);
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

Node* multiply_single(Node* l1,int num)
{
    Node* c=l1;
    int carry=0;
    Node* dummy=new Node(-1);
    Node* p=dummy;
    while(c!=nullptr or carry>0)
    {
        int a= (c!=nullptr?c->data:0);
        int prod=(a*num)+carry;
        int val=prod%10;
        carry=prod/10;
        p->next=new Node(val);
        p=p->next;
        if(c!=nullptr)
            c=c->next;
        
    }
    return dummy->next;
}
long long calculatesum(Node* head)
{
    long long sum=0;
    while(head!=NULL)
    {
        sum=sum*10+head->data;
        sum%=1000000007;
        head=head->next;
    }
    return sum;
}

void print(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  l1=reverseList(l1);
    l2=reverseList(l2);
    Node* dummy=new Node(-1) ;
    Node* p=dummy;
    while(l2!=nullptr)
    {
        Node* x=multiply_single(l1,l2->data);
        //print(x);
         p->next=addTwoNumbers(p->next,x);
         p=p->next;
         l2=l2->next;
    }
    //print(dummy->next);
    Node* nh= reverseList( dummy->next);
    long long ans=calculatesum(nh);
    return ans;
    return 0;
}

int main()
{
    return 0;
}