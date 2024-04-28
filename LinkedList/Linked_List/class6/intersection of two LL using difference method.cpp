#include<bits/stdc++.h>
using namespace std;
// using difference method
// first find diff b/w two LL then on th big LL run a while loop till diff
// now run both the pointers with same velocity when both pointer will meet
//that will be the intersection LL
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


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA==nullptr and headB==nullptr)
    {
        return NULL;
    }
   
    int list1=getlength(headA);
    int list2=getlength(headB);
    int diff=abs(list1-list2);

    ListNode* c1,*c2=nullptr ;

    if(list1>list2)
    {
        c1=headA;
        c2=headB;
    }
    else
    {
        c1=headB;
        c2=headA;
    }

    while(diff--)
    {
        c1=c1->next;
    }
    while( (c1!=nullptr and c2!=nullptr) and   c1!=c2)
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