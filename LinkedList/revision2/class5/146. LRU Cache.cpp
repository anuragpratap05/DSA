#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class ListNode
    {
    public:
        int val = 0;
        int key = 0;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode(int key, int val)
        {
            this->val = val;
            this->key = key;
        }
    };
    int cap;
    int currentCap = 0;
    map<int, ListNode *> m;
    ListNode *h = nullptr;
    ListNode *t = nullptr;
    void deleteNode(ListNode *node)
    {
        // cout<<"inside fn deleteNode:"<<endl;
        // cout<<h->val<<"   "<<t->val<<endl;

        // cout<<h->next->val<<"   "<<t->prev->val<<endl;
        if (node == this->h and node == this->t)
        {
            // cout<<"head and tail are pointing same node deleted it!!";
            h = t = nullptr;
            return;
        }

        if (node == this->h)
        {
            ListNode *f = node->next;
            // if(f==nullptr)
            // {
            //     cout<<"f is null;";
            // }
            node->next = nullptr;
            f->prev = nullptr;
            this->h = f;
        }
        else if (node == this->t)
        {
            ListNode *p = node->prev;
            p->next = nullptr;

            node->prev = nullptr;
            t = p;
        }
        else
        {
            ListNode *p = node->prev;
            ListNode *f = node->next;
            node->next = node->prev = nullptr;
            p->next = f;
            f->prev = p;
        }
    }
    void addLast(ListNode *node)
    {
        // cout<<"in fn addLast:"<<endl;
        if (this->h == nullptr and this->t == nullptr)
        {
            // cout<<"for key:"<<node->key<<"and value:"<<node->val<<" h and t are null"<<endl;
            this->h = this->t = node;
        }
        else
        {
            // cout<<"for key:"<<node->key<<"and value:"<<node->val<<" h and t are not  null"<<endl;

            this->t->next = node;
            node->prev = t;
            this->t = node;
        }
        // cout<<"h->val="<<h->val<<" and t->val="<<t->val<<endl;
    }
    int removeFirst()
    {

        if (h == nullptr and t == nullptr)
        {
            return 0;
        }
        int rv = h->key;
        if (h == t)
        {

            h = t = nullptr;
            return rv;
        }
        ListNode *f = h->next;
        h->next = f->prev = nullptr;
        h = f;
        return rv;
    }
    LRUCache(int capacity)
    {
        this->cap = capacity;
        m.clear();
    }

    int get(int key)
    {
        // cout<<"Inside fn get:"<<endl;
        int rv;
        if (m.find(key) != m.end())
        {
            ListNode *existedNode = m[key];
            rv = existedNode->val;
            deleteNode(existedNode);
            addLast(existedNode);
            return rv;
        }
        rv = -1;
        // cout<<rv<<endl;
        return rv;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            // cout<<"key:"<<key<<"alredy existed change its value ->";
            ListNode *existedNode = m[key];
            // cout<<"value before="<<existedNode->val<<endl;
            existedNode->val = value;
            deleteNode(existedNode);
            addLast(existedNode);
        }
        else
        {
            // cout<<"key:"<<key<<"ke liye nya node banan pdega"<<endl;
            ListNode *x = new ListNode(key, value);
            m[key] = x;
            addLast(x);
            currentCap++;
            if (currentCap > cap)
            {
                int existedKey = removeFirst();
                m.erase(existedKey);
                currentCap--;
            }
        }
    }
};

int main()
{
    return 0;
}