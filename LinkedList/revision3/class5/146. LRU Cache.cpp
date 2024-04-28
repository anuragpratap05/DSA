#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

public:
    class ListNode
    {
    public:
        int val, key;
        ListNode *next;
        ListNode *prev;
        ListNode(int key, int val)
        {
            this->val = val;
            this->key = key;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    ListNode *hd = nullptr;
    ListNode *tl = nullptr;
    unordered_map<int, ListNode *> mp;
    int cap;
    int curcap = 0;
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    ListNode *removeNode(ListNode *nd)
    {
        ListNode *p = nd->prev;
        ListNode *f = nd->next;

        if (p != nullptr)
            p->next = f;
        else
            hd = nd->next;

        if (f != nullptr)
            f->prev = p;
        else
            tl = nd->prev;

        nd->next = nd->prev = nullptr;
        return nd;
    }

    void addFirst(ListNode *nd)
    {
        if (hd == nullptr)
        {
            hd = tl = nd;
            return;
        }
        nd->next = hd;
        hd->prev = nd;
        hd = nd;
    }

    void makeRecent(ListNode *nd) 
    {
        ListNode *rn = removeNode(nd);
        addFirst(rn);
    }

    int get(int key)
    {
        int returnVal = -1;
        if (mp.find(key) != mp.end())
        {
            returnVal = mp[key]->val;
            makeRecent(mp[key]);
        }
        return returnVal;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->val = value;
            makeRecent(mp[key]);
            return;
        }

        ListNode *node = new ListNode(key, value);
        addFirst(node);
        mp[key] = node;

        if (this->curcap == this->cap)
        {
            int ndkey = tl->key;
            mp.erase(ndkey);
            removeNode(tl);
        }
        else
        {
            this->curcap++;
        }
    }
};

int main()
{
    return 0;
}