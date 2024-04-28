#include<bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

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
// phle single digit ke multiply ka function bnaya
ListNode* multiply_help(ListNode* head,int digit)
{
    ListNode* dummy= new ListNode(-1), *p=dummy;
    ListNode* c=head;
    int carry=0;
    while(c!=nullptr or carry!=0)
    {
        int prod=carry+digit * (c!=nullptr?c->val:0  );
        carry=prod/10;
        int num=prod%10;
        p->next= new ListNode(num);
        p=p->next;

        if(c!=nullptr)
        {
            c=c->next;
        }

    }
    return (dummy->next);
}




ListNode* addtwo(ListNode* l1,ListNode* l2)
{
    if(l1==nullptr or l2==nullptr)
    {
        return l1==nullptr?l2:l1;
    }
    ListNode* dummy=new ListNode(-1);
    ListNode* p=dummy;
    //l1=reverse(l1);
    //l2=reverse(l2);

    ListNode* c1=l1;
    ListNode* c2=l2;
    int carry=0;

    while(c1!=nullptr or c2!=nullptr or carry!=0)
    {
        int sum=carry+(c1!=nullptr?c1->val:0)+(c2!=nullptr?c2->val:0);
        carry=sum/10;
        p->next=new ListNode(sum%10);
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

// this is important
ListNode *multiplyTwoLL(ListNode *l1, ListNode *l2)
{
    l1=reverse(l1);
    l2=reverse(l2);
    ListNode* dummy=new ListNode(-1) ,*p=dummy,*c=l2 , *add=nullptr, *newlist;

    while(c!=nullptr)
    {
       newlist= multiply_help(l1,c->val);
       // ye line ka khel hai
       p->next=addtwo(p->next,newlist);
       p=p->next;
       c=c->next;

    }
    return reverse(dummy->next);
}

int main()
{
    return 0;
}