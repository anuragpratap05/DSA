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
bool hasCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr)
        {
            return false;
        }
        ListNode* s=head;
        ListNode* f=head;
    while(f->next!=nullptr and f->next->next!=nullptr)
    {
        f=f->next->next;
        s=s->next;
        if(s==f)
        {
            return true;
        }
    }
    return false; 
    }

int main()
{
    return 0;
}