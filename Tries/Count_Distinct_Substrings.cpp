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
int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->contains_key(s[j], node))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->links[s[j] - 'a'];
        }
    }

    return cnt + 1;
}

int main()
{
    return 0;
}