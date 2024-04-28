#include<bits/stdc++.h>
using namespace std;
// dummy node ka istemal krein
// prev pointer dummy node pe rhega fir aage bdhte jaw

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

    if(l1==nullptr)
    {
        return l2;
    }
    else if(l2==nullptr)
    {
        return l1;
    }

    ListNode* dummy= new ListNode(-1);
    ListNode* p=dummy;

    ListNode* c1=l1;
    ListNode* c2=l2;

    while(c1!=nullptr and c2!= nullptr)
    {
        if(c1->val <= c2->val)
        {
            p->next=c1;
            p=c1;
            c1=c1->next;
        }
        else
        {
            p->next=c2;
            p=c2;
            c2=c2->next;
        }
    }

    //if(c2==nullptr) ? p->next=c1:p->next=c2;

    p->next= c2==NULL ? c1 : c2;

    return dummy->next;
}

int main()
{

}