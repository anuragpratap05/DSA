#include<bits/stdc++.h>
using namespace std;
//find mid then break the link
// reverse the broke LL after mid
//compare each val of both LLs
//dont forget to make LL as it was before

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

bool isPalindrome(ListNode *head)
{
    if(head ==nullptr or head->next== nullptr)
    {
        return true;
    }

    bool flag=true;

    ListNode* mid=midNode(head);
    ListNode* nh=mid->next;
    mid->next=nullptr;
    nh=reverse(nh);

    ListNode* c1=head;
    ListNode* c2=nh;

    while(c2!=NULL)
    {
        if(c1->val != c2->val)
        {
            flag=false;
        }
        c1=c1->next;
        c2=c2->next;
    }
    nh= reverse(nh);
    mid->next=nh;
    return flag;

}

int main()
{

}