#include<bits/stdc++.h>
using namespace std;

//there are two methods

//good one is applying divide and conquer tech. 

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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode* help=nullptr;
    for(int i=0;i<lists.size();i++)
    {
        help=mergeTwoLists(help,lists[i]);
    }
    return help;
}

//******************************************************************************
// not accepted on leetcode
ListNode* help2(vector<ListNode *> &lists,int si,int ei)
{
    if(si==ei)
    {
        return lists[si];
    }
    
    int mid=(si+ei)/2;
    
    

    return mergeTwoLists(help2(lists,si,mid),help2(lists,mid+1,ei));
}

ListNode *mergeKLists_better(vector<ListNode *> &lists)
{
    int si=0;
    int ei=lists.size()-1;

    return help2(lists,si,ei);
}

int main()
{

}