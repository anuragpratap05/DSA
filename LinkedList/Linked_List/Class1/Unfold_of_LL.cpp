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

void unfold(ListNode *head)
{
    ListNode* nh = head->next;

    ListNode* c=head;
    ListNode* f=c->next;

    while(f->next!= NULL and c->next!= NULL)
    {
        c->next=f->next;
        c=c->next;
        
        f->next=c->next;
        if(c->next!=NULL)
            f=f->next;
        
    }

    nh=reverse(nh);

    c->next=nh;




}

int main()
{

}