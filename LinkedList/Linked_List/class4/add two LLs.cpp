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



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1==nullptr or l2==nullptr)
    {
        return l1==nullptr?l2:l1;
    }
    ListNode* dummy=new ListNode(-1);
    ListNode* p=dummy;
    l1=reverse(l1);
    l2=reverse(l2);

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
    return reverse(dummy->next);

}

int main()
{
    return 0;
}