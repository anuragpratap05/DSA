#include<bits/stdc++.h>
using namespace std;



  class Node
  {
  public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
   };

Node* head=nullptr;
Node* tail=nullptr;


  void addLast(int data)
  {
      Node* node=new Node(data);
    if(head == nullptr and tail ==nullptr)
    {
        
        head=tail=node;
    }
    else
    {
        tail->next=node;
        node->prev=tail;
        tail=tail->next;
    }



  }

void addFirst(int data)
{
    Node* node=new Node(data);
    if(head == nullptr and tail ==nullptr)
    {
        
        head=tail=node;
    }
    else{
        node->next=head;
        head->prev=node;
        head=node;
    }
}

int main()
{
    return 0;
}