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

int pivot(ListNode *head)
{
    int ans=0;
    while(head!=NULL)
    {
        ans= head->val;
        head=head->next;
         
    }

    return ans;
}

ListNode *segregateOnLastIndex(ListNode *head)
{
        if(head==nullptr or head->next==nullptr)
    {
        return head;
    }
    int pivotIdx=pivot(head);
   ListNode* sdummy=new ListNode(-1);
  ListNode* s=sdummy;
  ListNode* ldummy=new ListNode(-1);
  ListNode* l=ldummy;

  ListNode* c=head;

  while(c!=nullptr)
  {
      if(c->val <=pivotIdx)
      {
          s->next=c;
          s=c;
          
      }
      else
      {
         l->next=c;
          l=c; 

      }
      c=c->next;
  }
  s->next=l->next=nullptr;
  s->next=ldummy->next;
  return s;
}

int main()
{
    return 0;
}