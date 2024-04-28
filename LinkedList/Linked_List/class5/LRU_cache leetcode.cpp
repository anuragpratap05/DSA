#include<bits/stdc++.h>
using namespace std;
// is code me map ki jgh vector le le jiska size 10^4+1 ho to jldi chlega code kyuki
// key ki range10^4 tak hi hai pe vector declaration me dikkt aa rhi h

class LRUCache {

private:
    class listnode{
    public:
    int key,value;
    listnode* next=nullptr;
    listnode* prev=nullptr;
    listnode(int key,int value)
    {
        this->key=key;
        this->value=value;
    }
    
};


 unordered_map<int,listnode*> m;
 
//  vector<listnode*> m;
//  public:
//      LRUCache() : m(10001,NULL) {}
 int size;
 int capacity;
 listnode* head=nullptr;
 listnode* tail=nullptr;

//  vector<listnode*> m;
//  public:
//      LRUCache() : m(10001,NULL) {}


public:

    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        m.clear();
        this->head=nullptr;
        this->tail=nullptr;
    }
      listnode* removeFirst() {
        listnode* node = this -> head;
        if (this->head == this->tail)
            this->head = this->tail = nullptr;
        else {
            this->head = node->next;
            node->next = this->head->prev = nullptr;
        }
        this->size--;
        return node;
    }

     listnode* removeLast() {
        listnode* node = this->tail;
        if (this->head == this->tail)
            this->head = this->tail = nullptr;
        else {
            this->tail = node->prev;
            node->prev = this->tail->next = nullptr;
        }
        this->size--;
        return node;
    }

     listnode* remove(listnode* node) {
        if (node == this->head)
            return removeFirst();
        else if (node == this->tail)
            return removeLast();
        else {
            listnode* prev = node->prev, *forw = node->next;

            prev->next = forw;
            forw->prev = prev;

            node->next = node->prev = nullptr;
            this->size--;
            return node;
        }
    }
    // void remove(listnode* node)
    // {
    //     if(head==nullptr and tail==nullptr)
    //     {
    //         return;
    //     }
    //     if(head== tail)
    //     {
    //         head=tail=nullptr;
    //         return;
    //     }
    //     //size--;
    //     listnode* c=node;
    //     listnode* p=c->prev;
    //     if(p==nullptr)
    //     {
    //         head=c->next;
    //         c->next->prev=nullptr;
    //         c->next=nullptr;
    //         return;
    //     }
    //     listnode* n=c->next;
    //     if(n==nullptr)
    //     {
    //         tail=c->prev;
    //         c->prev->next=nullptr;
    //         c->prev=nullptr;

    //         return;
    //     }
    //     p->next=n;
    //     n->prev=p;
    //     c->prev=nullptr;
    //     c->next=nullptr;


    // }
    void addlast(listnode* node)
    {
        //size++;
        if(head==nullptr and tail==nullptr)
        {
            head=tail=node;
        }
        else
        {
            tail->next=node;
            node->prev=tail;
            tail=tail->next;
        }
        return;
    }
    private:
    void makefirst(listnode* node)
    {
        remove(node);
        addlast(node);
    }
    public:
    int get(int key) {
        if(m.find(key)== m.end())
        {
            return -1;
        }
        else
        {
            listnode* node=m[key];
            makefirst(node);
            return node->value;
        }
        
    }
    
    void put(int key, int value) {

        
        //listnode* temp=()
        if(m.find(key)!=m.end())
        {
            listnode* node=m[key];
            node->value=value;
            makefirst(node);
        }
        else
        {
            
            listnode* node=new listnode(key,value);
            
            if(size==capacity)
            {
                listnode* rn = removeFirst();
                m.erase(rn->key);
                size--;
                
            }
            addlast(node);
            m[key]=node;
            size++;
            
        }


        

        

        
    }
};

int main()
{
    return 0;
}