#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int data;
    ListNode* next;
    
    ListNode(int x){
        data = x;
        next = NULL;
    }
    
};
  ListNode* hasCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr)
    {
        return nullptr;
    }
    ListNode* s=head;
    ListNode* f=head;

    while(f->next != nullptr and f->next->next != nullptr)
    {
        f=f->next->next;
        s=s->next;
        if(s==f)
        {
            return f;
        }
    }
    return nullptr;
    }
    ListNode *detectCyclenode(ListNode *head) {
        
        ListNode* meeting=hasCycle(head);
        if(meeting ==nullptr)
        {
            return nullptr;
        }
        ListNode* s=head;
        ListNode* f=meeting;
        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }
        return s;
        
    }

int main()
{
    return 0;
}