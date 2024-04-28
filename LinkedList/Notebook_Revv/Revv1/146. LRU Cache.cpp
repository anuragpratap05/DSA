#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    class ListNode
    {
    public:
        int key, val;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        ListNode(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    int allowedcap;
    int curCap = 0;
    ListNode *oh = nullptr, *ot = nullptr;
    unordered_map<int, ListNode *> mp;

    void add(ListNode *node)
    {
        if (oh == nullptr and ot == nullptr)
        {
            oh = ot = node;
            return;
        }
        oh->next = node;
        node->prev = oh;
        oh = node;
    }

    void remove(ListNode *node)
    {
        if (node == oh and node == ot)
        {
            oh = ot = nullptr;
        }
        else if (node == oh)
        {
            ListNode *prevNd = oh->prev;
            oh->prev = nullptr;
            prevNd->next = nullptr;
            prevNd = oh;
        }
        else if (node == ot)
        {
            ListNode *nextNd = ot->next;
            ot->next = nullptr;
            nextNd->prev = nullptr;
            ot = nextNd;
        }
        else
        {
            ListNode *prevNd = node->prev;
            ListNode *nextNd = node->next;

            node->prev = nullptr;
            node->next = nullptr;

            prevNd->next = nextNd;
            nextNd->prev = prevNd;
        }
    }

public:
    LRUCache(int capacity)
    {
        this->allowedcap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        ListNode *node = mp[key];

        if (node != oh)
        {
            remove(node);
            add(node);
        }

        return node->val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            ListNode *node = mp[key];
            node->val = value;
            if (node != oh)
            {
                remove(node);
                add(node);
            }
            return;
        }
        ListNode *node = new ListNode(key, value);
        mp[key] = node;
        add(node);
        this->curCap++;
        if (curCap > this->allowedcap)
        {
            ListNode *node = ot;
            int ndKey = node->key;
            remove(node);
            mp.erase(ndKey);
            this->curCap--;
        }
    }
};

int main()
{
    return 0;
}