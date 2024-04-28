#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int end = 0;
    int prefix = 0;
    Node *links[26];

    bool contains_key(char word, Node *node)
    {
        int idx = word - 'a';
        return (links[idx] != nullptr);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

class Trie
{

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if(!node->contains_key(ch,node))
            {
                node->put(ch, new Node());
            }
            node = node->links[ch - 'a'];
            node->prefix++;
        }
        node->end++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (!node->contains_key(ch, node))
            {
                return 0;
               
            }
             node = node->links[ch - 'a'];
            // node->prefix++;
        }
        return node->end;
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (!node->contains_key(ch, node))
            {
                return 0;
            }
            node = node->links[ch - 'a'];
           // node->prefix++;
        }
        return node->prefix;
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (!node->contains_key(ch, node))
            {
                return;
                //node->put(ch, new Node());
            }
            node = node->links[ch - 'a'];
            node->prefix--;
        }
        node->end--;
    }
};

int main()
{
    return 0;
}