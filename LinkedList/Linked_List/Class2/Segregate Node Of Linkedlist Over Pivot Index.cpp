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

ListNode* segregate(ListNode* head, int pivotIdx)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }ListNode* pivtnode=head;
    
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

    s->next=pivtnode;
    pivtnode->next=ldummy->next;
    return sdummy->next;
}

int main()
{
    return 0;
}