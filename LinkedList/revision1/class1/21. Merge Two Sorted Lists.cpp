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


int main()
{
    return 0;
}