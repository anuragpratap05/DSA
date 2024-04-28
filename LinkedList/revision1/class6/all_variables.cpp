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
    void allvariables(ListNode *head) {
        
        ListNode* meeting=hasCycle(head);
        if(meeting ==nullptr)
        {
            return ;
        }
        ListNode* s=head, *f=meeting;
        int a=0,mdash=0;
        while(s!=f)
        {
            a++;
            s=s->next;
            f=f->next;
            if(f==meeting)
            {
                mdash++;
            }
        }

        s=meeting;
        s=s->next;
        int cyclelength=1;
        while(s!=meeting)
        {
            cyclelength++;
        }

        int c=a-mdash*cyclelength;
        int b=cyclelength-c;
        int m=mdash+1;

        
        
    }   

int main()
{
    return 0;
}