#include<bits/stdc++.h>
using namespace std;

// mid mngwao
    // mid se todke bchi hui ko reverse kro, fir jod do (acc to ques)

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

ListNode *midNode(ListNode *head)
{
    if(head == NULL or head->next==NULL)
    {
        return head;
    }

    ListNode* slow= head;
    ListNode* fast=head;

    while(fast->next != NULL and fast->next->next != NULL)
    {
        fast=fast->next->next;
        slow = slow->next;
    }

    return slow;
    
}

void fold(ListNode *head)
{

    if(head==NULL or head->next==NULL)
    {
        return;
    }
    
    ListNode* mid=   midNode(head);
    ListNode* nh=mid->next;
    mid->next=nullptr;
    nh=reverse(nh);


    ListNode* c1=head;
    ListNode* c2=nh;
    while(c1!=nullptr and c2!=nullptr)
    {
        ListNode* f1=c1->next;
        ListNode* f2=c2->next;

        c1->next=c2;
        c2->next=f1;

        c1=f1;
        c2=f2;
    }
}

int main()
{

}