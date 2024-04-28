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
ListNode *reverse(ListNode *head)
{

    if(head == nullptr or head->next == nullptr)
    {
        return head;
    }

    ListNode* prev= nullptr;
    ListNode* curr= head;
    ListNode* forw= curr->next;

    while(curr != nullptr)
    {
        curr->next= prev;

        prev=curr;
        curr=forw;
        if(forw!= nullptr)
            forw=curr->next;
    }
    return prev;
}


ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2)
{
  if(l2==nullptr)
  {
      return l1;
  }
  l1=reverse(l1);
  l2=reverse(l2);
  ListNode* dummy=new ListNode(-1), *p=dummy,*c1=l1, *c2=l2;
    int borrow=0;

    while(c1!=nullptr)
    {
        int sub=  borrow+c1->val-(c2!=nullptr?c2->val:0);
        if(sub<0)
        {
            borrow=-1;
            sub+=10;
        }
        else{
            borrow=0;
        }
        p->next=new ListNode(sub);
        p=p->next;
        c1=c1->next;
        if(c2!=nullptr)
        {
            c2=c2->next;
        }
    }
    //ListNode* nh= reverse(dummy->next);

    ListNode* head = reverse(dummy->next), *curr = head;
        while (curr != nullptr && curr->val == 0) {
            ListNode* forw = curr->next;
            curr->next = nullptr;
            curr = forw;
        }

        return curr != nullptr ? curr : new ListNode(0);



    // while(nh!=nullptr)
    // {
    //     //ListNode* f=nh->next;
    //     if(nh->val != 0)
    //     {
    //         return nh;
    //     }
    //     nh=nh->next;
    // }
    // return new ListNode(0);
}

int main()
{
    return 0;
}