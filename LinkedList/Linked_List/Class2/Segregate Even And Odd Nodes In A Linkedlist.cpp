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

ListNode *segregateEvenOdd(ListNode *head)
{
     ListNode* c1=head;
    ListNode* e=new ListNode(-1);
    ListNode* p=e;
    ListNode* o=new ListNode(-1);
    ListNode* t=o;

    while(c1!=nullptr)
    {
        if(c1->val %2==0)
        {
            e->next=c1;
            e=c1;
            c1=c1->next;
        }
        else
        {
            o->next=c1;
            o=c1;
            c1=c1->next;
        }
    }
    o->next=nullptr;
    e->next=nullptr;
    e->next=t->next;
    return p->next;
}


int main()
{

}