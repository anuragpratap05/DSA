#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;
    
    ListNode(int x){
        val = x;
        next = NULL;
    }
    
};
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* b=head;
    ListNode* a=head;
    while(n--)
    {
        b=b->next;
    }     
    if(b==nullptr)
    {
        return a->next;
    }
    while(b->next!=nullptr)
    {
        a=a->next;
        b=b->next;
    }
    a->next=a->next->next;
    return head;
}

int main()
{
    return 0;
}