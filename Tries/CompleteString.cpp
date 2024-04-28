#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool flag = false;
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
    Node *root;

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
            if (!node->contains_key(ch, node))
            {
                node->put(ch, new Node());
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    bool is_complete_word(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            // if (!node->contains_key(ch, node))
            // {
            //     return false;
            // }
            node = node->links[ch - 'a'];
            if(!node->flag)
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie t;
    for(auto &word:a)
    {
        t.insert(word);
    }

    string lw = "";
    for(auto& word:a)
    {
        if(t.is_complete_word(word))
        {
            if(word.size()>lw.size())
            {
                lw = word;
            }
            else if(word.size()==lw.size() and word<lw)
            {
                lw = word;
            }
        }
    }

    return (lw == "" ? "None" : lw);
}

int main()
{
    return 0;
}