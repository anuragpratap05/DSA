#include<bits/stdc++.h>
using namespace std;

// 

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

vector<ListNode*> segregate(ListNode* head, int pivotIdx)
{
    if(head==nullptr or head->next==nullptr)
    {
        return {head,head,head,head,head};
    }
    ListNode* pivtnode=head;
    
    while(pivotIdx--)
    {
        pivtnode=pivtnode->next;
    }

    

    ListNode* ldummy = new ListNode(-1);
    ListNode* l=ldummy;
    ListNode* sdummy = new ListNode(-1);
    ListNode* s=sdummy;

    ListNode* c=head;

    while(c!=nullptr)
    {
       if( c!=pivtnode and c->val <=pivtnode->val)
      {
          s->next=c;
          s=c;
          
      }
      else if(c!=pivtnode)
      {
         l->next=c;
          l=c; 

      }
      c=c->next;
        
    }
    pivtnode->next=l->next=s->next=nullptr;

    return {sdummy->next,s,pivtnode,ldummy->next,l};

    // s->next=pivtnode;
    // pivtnode->next=ldummy->next;
    // return sdummy->next;
}

int length(ListNode* head)
{
   int c=0;
   while(head!=nullptr)
   {
       c++;
       head=head->next;
       
   } 
   return c;
}
vector<ListNode*> mergelists(vector<ListNode*> left,ListNode* pn,vector<ListNode*> right)
{
    ListNode* h1=left[0];
    ListNode* t1=left[1];
    //ListNode* pn=vec[2];
    ListNode* h2=right[0];
    ListNode* t2=right[1];

    

    if(t1!=nullptr)
    {
        t1->next=pn;
    }
    if(h2!=nullptr)
    {
        pn->next=h2;
    }

    ListNode* newh1=  (h1!=nullptr?h1:pn);
    ListNode* newt2= (t2!=nullptr?t2:pn);
    return {newh1,newt2};  
}

vector<ListNode*> quicksort_(ListNode* head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return {head,head};
    }

    int len=length(head);
    int pivtidx=len/2;

    vector<ListNode*>vec     =   segregate(head,pivtidx);

    ListNode* h1=vec[0];
    ListNode* t1=vec[1];
    ListNode* pn=vec[2];
    ListNode* h2=vec[3];
    ListNode* t2=vec[4];
    vector<ListNode*> left=quicksort_(h1);
    vector<ListNode*> right=quicksort_(h2);

    return mergelists(left,pn,right);
}

ListNode* quicksort(ListNode* head)
{
    return quicksort_(head)[0];
}

int main()
{
    return 0;
}