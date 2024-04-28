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
int getlen(ListNode* head)
{
    int len=0;
    while(head!=nullptr)
    {
        len++;
        head=head->next;
    }
    return len;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }
  ListNode* c=head;
  ListNode* p=nullptr;
  ListNode* f=c->next;

  int tar=getlen(head)-n;
  if(tar==0)
  {
      return head->next;
  }

  while(tar--)
  {
      
      p=c;
      c=c->next;
      f=f->next;
  }

  c->next=nullptr;
  p->next=f;
  return head;


}

int main()
{
    return 0;
}