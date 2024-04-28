#include<bits/stdc++.h>
using namespace std;

//reverse in group of k
// take ori head  ori tail temp head temp tail


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



int length(ListNode* head)
{
    int len=0;
    while(head!=nullptr)
    {
        head =head->next;
        len++;
    }
    return len;
}
 ListNode *th =nullptr, * tt= nullptr;
void addfirst(ListNode* node)
{
    if(th == nullptr)
    {
        th=tt=node;
    }
    else
    {
        node->next=th;
        th=node;
    }
}

ListNode* reverseInKGroup(ListNode* head, int k)
{
    if(head == nullptr or head->next == nullptr or k<=1)
    {
        return head;
    }
    ListNode* curr=head;
    
    int len=length(head);

    ListNode* oh =nullptr, *ot =nullptr;

    while(curr!=nullptr and len>=k)
    {
        int tempk=k;
        while(tempk-- >0 )
        {
            ListNode* f=curr->next;
            curr->next=nullptr;
            addfirst(curr);
            curr=f;
            //f=f->next;
        }
        if(oh == nullptr and ot== nullptr)
        {
            oh=th;
            ot=tt;
        }
        else
        {
            ot->next=th;
            ot=tt;
        }
        th=tt= nullptr;
        len -= k;
    }

    if(len>0)
    {
        ot->next = curr;
    }

    return oh;

}

int main()
{

}