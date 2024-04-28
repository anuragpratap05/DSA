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



ListNode* reverseKGroup(ListNode* head, int k)
{
    if(k<=1 or head==nullptr or head->next==nullptr)
    {
        return head;
    }
    ListNode* gh=head;
    ListNode* c=head;
    ListNode* oh=nullptr;
    ListNode* h2=head;
    ListNode* f=head->next;
    int cnt=1;
    while(c!=nullptr)
    {
        c=f;
        if(f!=nullptr)
        {
            cnt++;
            f=f->next;
        }
        if(cnt==k)
        {
            c->next=nullptr;
           ListNode* nh=reverseList(gh);
           if(gh==head)
           {
               oh=nh;
           }
           h2->next=nh;
           h2=gh;
           gh->next=f;
           gh=f;
           cnt=1;
           c=f;
           if(f!=nullptr)
            {
                //cnt++;
                f=f->next;
            }

           //c=f;
        }
    }
    return oh;
}

ListNode* th=nullptr;
ListNode* tt=nullptr;

int length(ListNode* head)
{
    int c=0;
    while(head!=nullptr)
    {
        head=head->next;
        c++;
    }
    return c;
}

void addfirst(ListNode* node)
{
    if(th==nullptr)
    {
        th=tt=node;
    }
    else
    {
        node->next=th;
        th=node;
    }
}
// method2
ListNode* reverseKGroup2(ListNode* head, int k)
{
         if(head==nullptr or head->next==nullptr or k<=1)
    {
        return head;
    }
    int l=length(head);
    ListNode* c=head;
    ListNode* f=c->next;
    ListNode* oh=nullptr,* ot=nullptr;

    while(c!=nullptr and l>=k)
    {
        int tempk=k;
        while(tempk--)
        {
            c->next=nullptr;
            addfirst(c);
            c=f;
            if(f!=nullptr)
            f=f->next;
        }
        if(oh==nullptr)
        {
            oh=th;
            ot=tt;
        }
        else
        {
            ot->next=th;
            ot=tt;
        }
        th=tt=nullptr;
        l-=k;
        

    }
        ot->next=c;
        return oh;
}

int main()
{
    return 0;
}