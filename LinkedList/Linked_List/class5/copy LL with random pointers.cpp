#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int val = 0;
    Node *next = nullptr;
    Node *random = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node *copyRandomList(Node *head)
{
    map<Node*,Node*> m;
    Node* c=head;
    Node* dummy=new Node(-1);
    Node* p=dummy;
    while(c!=nullptr)
    {
        Node* node=new Node(c->val);
        p->next=node;
        p=p->next;
        m[c]=node;
        c=c->next;

    }

    Node* nh=dummy->next;
    Node* c1=head;
    Node* c2=dummy->next;
    while(c1!=nullptr)
    {
        c2->random=   c1->random !=nullptr?  m[c1->random]:nullptr;
        c1=c1->next;
        c2=c2->next;
    }
    return nh;
}

int main()
{
    return 0;
}