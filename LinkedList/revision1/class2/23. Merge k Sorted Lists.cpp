#include<bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data = 0;
    ListNode *next = nullptr;

    ListNode(int data)
    {
        this->data = data;
    }
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if(list1 ==nullptr or list2==nullptr )
    {
        return (list1==nullptr?list2:list1);
    }
    ListNode* dummy= new ListNode(-1);
    ListNode* p=dummy;
    ListNode* c1=list1;
    ListNode* c2=list2;

    while(c1!=nullptr and c2!=nullptr)
    {
        if(c1->data<= c2->data)
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
    p->next= (c2!=nullptr?c2:c1);
    return dummy->next;
}

ListNode* merge(vector<ListNode*>& lists,int si,int ei)
{
    if(si==ei)
    {
        return lists[si];
    }
    int mid=(si+ei)/2;

 

    ListNode* l1=merge(lists,si,mid);
    ListNode* l2=merge(lists,mid+1,ei);

    ListNode* final=mergeTwoLists(l1,l2);
    return final;

}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int si=0;
    int ei=lists.size()-1;

    return merge(lists,si,ei);

    
}

int main()
{
    return 0;
}