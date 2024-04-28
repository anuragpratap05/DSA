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

ListNode *reverseInRange(ListNode *head, int m, int n)
{
    if(head == nullptr or head->next ==nullptr)
    {
        return head;
    }
    ListNode* s= head;
    ListNode* p=nullptr;
    ListNode* e=head;
    ListNode* f=nullptr;
    int tempm=m;

    while(--n)
    {
        
        if(tempm>1)
        {
            p=s;
            s=s->next;
            tempm--;
        }

        e=e->next;
    }
    f=e->next;
    if(p != nullptr)
        p->next=nullptr;
    e->next=nullptr;

    ListNode* nh=reverse(s);
    if(p != nullptr)
        p->next=nh;
    if(f != nullptr)
    {
        s->next=f;
    }
        

    if(m==1)
    {
        return nh;
    }
    else{
          return head;  
    }   

}


int main()
{

return 0;
}