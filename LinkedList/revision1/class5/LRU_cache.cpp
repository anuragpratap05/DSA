#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    class Node{
        public:
        int val,key;
        Node* prev=NULL;
        Node* next=NULL;
        Node(int key,int val)
        {
            this->val=val;
            this->key=key;
            this->prev=NULL;
            this->next=NULL;
        }

    };
    int capacity;
    int size;
    Node* head=NULL, *tail=NULL;
    //map<int,Node*> m;
    vector<Node*> m;

    
    void addnodeinlast(Node* node)
    {
        //size++;
        if(head==nullptr and tail==nullptr)
        {
            head=tail=node;
            return;
        }
        tail->next=node;
        node->prev=tail;
        tail=node;
    }

    void deletenode(Node* node)
    {
        //size--;
        if(head==nullptr or (node->next==nullptr and node->prev==nullptr))
        {
            return;
        }
        if(node==head)
        {
            Node* agla=node->next;
            node->next=nullptr;
            agla->prev=nullptr;
            head=agla;

        }
        else if(node==tail)
        {
            Node* pichla=node->prev;
            node->prev=nullptr;
            pichla->next=nullptr;
            tail=pichla;
        }
        else{
            Node* agla=node->next;
            Node* pichla=node->prev;
            pichla->next=agla;
            agla->prev=pichla;

        }
    }
    void makerecent(Node* node)
    {
        deletenode(node);
        addnodeinlast(node);
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        m.clear();
        m.resize(10001,NULL);
    }
    
    int get(int key) {
        if(m[key]==NULL)
        {
            return -1;
        }
        Node* node=m[key];
        int data=node->val;
        makerecent(node)  ;
        return  data;
    }
    
    void put(int key, int value) {
        if(m[key]!=NULL)
        {
            Node* node=m[key];
            node->val=value;
            makerecent(node);

        }
        else{
            Node* node=new Node(key,value);
            m[key]=node;
            if(capacity== size)
            {
                m[head->key]=NULL;
                deletenode(head);
                size--;
                
            }
            addnodeinlast(node);
            size++;
        }
    }
};


int main()
{
    return 0;
}