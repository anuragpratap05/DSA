#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    Node* dummy=new Node(-1);
    Node* p=dummy;
    Node* c=head;
    map<Node*,Node*> m;
    while(c!=nullptr)
    {
        Node* node=new Node(c->val);
        m[c]=node;
        p->next=node;
        p=p->next;
        c=c->next;
    }
    c=head;

    while(c!=nullptr)
    {
        Node* node=m[c];
        Node* rnode=c->random;
        node->random=m[rnode];
        c=c->next;
    }
    return dummy->next;

}
// O(1) space
void copylist(Node* head)
{
    Node* c=head;
    while(c!=nullptr)
    {
        Node* f=c->next;
        Node* node= new Node(c->val);
        c->next=node;
        node->next=f;
        c=f;


    }
}

void setrandomp(Node* head)
{
   Node* c=head;
    while(c!=nullptr)
    {
        Node* rp_node=c->random;
        if(rp_node==nullptr)
        {
          c->next->random=nullptr;  
        }
        else
            c->next->random=rp_node->next;

        c=c->next->next;
    }
}
Node* freeall(Node* head)
{
    Node* dummy= new Node(-1);
    Node* p=dummy;

    Node* c=head;

    while(c!=nullptr)
    {
        p->next=c->next;
        c->next=c->next->next;
        p=p->next;
        c=c->next;
    }
    return dummy->next;
}

Node* copyRandomList_O1(Node* head)
{
    
    copylist(head);
    setrandomp(head);
    return freeall(head);
}

int main()
{
    return 0;
}