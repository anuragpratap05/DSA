#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

int dia = 0;
class p
{
public:
    int dia = 0;
    int h1 = -1;
    int h2 = -1;
};

p diameter_help(Node *root)
{
    p x;
    for (auto child : root->children)
    {
        p sa = diameter_help(child);
        x.dia = max(x.dia, sa.dia);
        if (sa.h1 > x.h1)
        {
            x.h2 = x.h1;
            x.h1 = sa.h1;
        }
        else if (sa.h1 > x.h2)
        {
            x.h2 = sa.h1;
        }
    }
    if (x.h2 != -1)
        x.dia = max(x.dia, x.h1 + x.h2 + 2);
    x.h2 += 1;
    x.h1 += 1;
    return x;
}

int diameter(Node *root)
{
    return diameter_help(root).dia;
}

int main()
{
    return 0;
}