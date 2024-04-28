#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val = 0;
    vector<Node *> children;
    // Node(int val, vector<>)
    // {
    //     this->val = val;
    // }
};

bool printRootToGivenNodePath(Node *root, int uniqueValue)
{
    if (root->children.size() == 0 or root->val == uniqueValue)
    {
        if (root->children.size() == 0)
        {
            return false;
        }
        else
        {
            cout << root->val << " ";
            return true;
        }
    }

    bool foundUniqueNode = false;
    for (Node *child : root->children)
    {
        foundUniqueNode = printRootToGivenNodePath(child, uniqueValue);
        if (foundUniqueNode)
        {
            cout << root->val << " ";
        }
    }

    return foundUniqueNode;
}

int main()
{

    return 0;
}