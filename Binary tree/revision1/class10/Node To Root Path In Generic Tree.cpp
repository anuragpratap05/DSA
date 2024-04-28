#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};

bool nodeToRootPath_(Node *node, int data, vector<int> &ans)
{

    bool res = (node->data == data);
    for (auto child : node->children)
    {
        res = res or nodeToRootPath_(child, data, ans);
    }
    if (res)
        ans.push_back(node->data);
    return res;
}

vector<int> nodeToRootPath(Node *node, int data)
{

    vector<int> ans;
    nodeToRootPath_(node, data, ans);
    return ans;
}

int main()
{
    return 0;
}