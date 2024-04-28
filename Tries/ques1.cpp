#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool flag = false;
    Node *links[26];

    bool contains_key(char word,Node* node)
    {
        int idx = word - 'a';
        return (links[idx] != nullptr);
    }
    void put(char ch,Node* node)
    {
        links[ch - 'a'] = node;
    }
};

class Trie
{
    Node *root ;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if(!node->contains_key(ch,node))
            {
                node->put(ch, new Node());
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length();i++)
        {
            char ch = word[i];
            if (!node->contains_key(ch, node))
            {
                return false;
            }
            node = node->links[ch - 'a'];
        }

        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            char ch = prefix[i];
            if (!node->contains_key(ch, node))
            {
                return false;
            }
            node = node->links[ch - 'a'];
        }

        return true;
    }
};

int main()
{
    return 0;
}