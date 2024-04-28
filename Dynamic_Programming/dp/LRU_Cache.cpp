#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class ListNode
    {
    public:
        int key, val;
        ListNode *prev = nullptr, *next = nullptr;
        ListNode(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    unordered_map<int, ListNode *> mp;
    ListNode *hd = nullptr, *tl = nullptr;

    void removeNode(ListNode *node)
    {
        if (node == hd and node == tl)
        {
            hd = tl = nullptr;
        }
        else if (node == hd)
        {
            ListNode *forw = node->next;
            node->next = nullptr;
            forw->prev = nullptr;
            hd = forw;
        }
        else if (node == tl)
        {
            ListNode *prevNode = tl->prev;
            tl->prev = nullptr;
            prevNode->next = nullptr;
            tl = prevNode;
        }
        else
        {
            ListNode *forw = node->next;
            ListNode *prevNode = node->prev;
            node->next = node->prev = nullptr;
            prevNode->next = forw;
            forw->prev = prevNode;
        }
    }

    void addNodeOnHead(ListNode *node)
    {
        if (hd == nullptr and tl == nullptr)
        {
            hd = tl = node;
        }
        else
        {
            node->next = hd;
            hd->prev = node;
            hd = node;
        }
    }

    int allowedCapacity = 0;
    int currcapacity = 0;
    LRUCache(int capacity)
    {
        this->allowedCapacity = capacity;
    }

    int get(int key)
    {
        int value = -1;

        if (mp.find(key) != mp.end())
        {
            ListNode *node = mp[key];
            value = node->val;
            removeNode(node);
            addNodeOnHead(node);
        }

        return value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            ListNode *node = mp[key];
            node->val = value;
            removeNode(node);
            addNodeOnHead(node);
        }
        else
        {
            ListNode *newNode = new ListNode(key, value);
            mp[key] = newNode;
            addNodeOnHead(newNode);
            currcapacity++;
            if (currcapacity > allowedCapacity)
            {
                int keyoftail = tl->key;
                removeNode(tl);
                mp.erase(keyoftail);
                currcapacity--;
            }
        }
    }
};


int main()
{
    return 0;
}