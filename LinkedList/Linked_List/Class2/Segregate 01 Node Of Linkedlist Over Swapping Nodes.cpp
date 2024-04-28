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

ListNode *segregate01(ListNode *head)
{
    ListNode* c=head;
    ListNode* zero=new ListNode(-1);
    ListNode* zerop=zero;
    ListNode* one=new ListNode(-1);
    ListNode* onep=one;

     while(c!=nullptr)
    {
        if(c->val == 0)
        {
            zero->next=c;
            zero=zero->next;
        }
        else
        {
            one->next=c;
            one=one->next;

        }
        c=c->next;
    }

    zero->next=nullptr;
    one->next=nullptr;

    zero->next=onep->next;
    return zerop->next;


}

int main()
{

return 0;
}