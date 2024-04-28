#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[2];
    bool contains(int bit)
    {
        return (links[bit] != nullptr);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->contains(bit))
            {
                node->put(bit, new Node());
            }
            node = node->links[bit];
        }
    }


    int get_max(int x)
    {
        int max_num = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (node->contains(1 - bit))
            {
                max_num |= (1 << i);
                node = node->links[1 - bit];
            }
            else
            {
                //max_num |= (bit);
                node = node->links[bit];
            }
        }
        return max_num;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie t;
    for(int e:arr1)
    {
        t.insert(e);
    }
    int maxi = 0;
    for(int e:arr2)
    {
        maxi = max(maxi, t.get_max(e));
    }
    return maxi;
}

int main()
{
    return 0;
}