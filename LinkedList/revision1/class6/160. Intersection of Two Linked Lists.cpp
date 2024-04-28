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

int getlength(ListNode* head)
{
    int len=0;
    while(head!=nullptr)
    {
        len++;
        head=head->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=getlength(headA);
        int len2=getlength(headB);
        int diff=0;
        ListNode* c1;
        ListNode* c2;
        if(len1>len2)
        {
             c1=headA;
             c2=headB;
            diff=len1-len2;
        }
        else{
             c2=headA;
             c1=headB;
            diff=len2-len1;
        }
        while(diff--)
        {
           c1=c1->next; 
        }

        while(c1!=c2)
        {
            c1=c1->next;
            c2=c2->next;
        }
        return c1;

    }

int main()
{
    return 0;
}