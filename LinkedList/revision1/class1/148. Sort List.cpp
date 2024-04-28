#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};
Node* middleNode(Node* head)
{
    Node* slow=head,*fast=head;
    while(fast->next!=nullptr and fast->next->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;


}
Node* mergeTwoLists(Node* list1, Node* list2)
{
    Node* dummy= new Node(-1);
    Node* p=dummy;
    Node* c1=list1;
    Node* c2=list2;

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
Node* sortList(Node* head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }
    Node* mid=middleNode(head);
    Node* nh=mid->next;
    mid->next=nullptr;
    Node* l1=sortList(head);
    Node* l2=sortList(nh);

    Node*  final=mergeTwoLists(l1,l2);
    return final;



}

int main()
{
    return 0;
}