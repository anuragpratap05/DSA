#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
Node *merge(Node *l1, Node *l2)
{
    if(l1==nullptr or l2==nullptr)
    {
        return (l1==nullptr?l2:l1);
    }
    Node* dummy=new Node(-1);
    Node* p=dummy;
    Node* c1=l1;
    Node *c2 = l2;

    while(c1!=nullptr and c2!=nullptr)
    {
        if(c1->data<c2->data)
        {
            p->next=c1;
            c1->prev=p;
            p=c1;
            c1=c1->next;
        }
        else{
            p->next = c2;
            c2->prev = p;
            p = c2;
            c2 = c2->next;
        }
    }
    if(c1==nullptr)
    {
        p->next=c2;
        c2->prev=p;
    }
    else
    {
        p->next = c1;
        c1->prev = p;
    }
    Node *rn = dummy->next;
    dummy->next = nullptr;
    rn->prev = nullptr;
    return rn;
}
struct Node *midlle(struct Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }
    struct Node *s = head;
    struct Node *f = head;
    while (f->next != nullptr and f->next->next != nullptr)
    {

        s = s->next;
        f = f->next->next;
    }
    return s;
}
Node *sortDoubly(Node *head)
{
    if(head==nullptr or head->next==nullptr)
    {
        return head;
    }

    Node* midnode=midlle(head);
    Node* rh=midnode->next;
    midnode->next=rh->prev=nullptr;

    Node* l1=sortDoubly(head);
    Node *l2 = sortDoubly(rh);

    return merge(l1,l2);


}

int main()
{
    return 0;
}