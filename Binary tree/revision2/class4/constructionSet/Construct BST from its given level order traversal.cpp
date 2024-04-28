#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class trplet
{
public:
    Node *par = nullptr;
    int lr = -1e9, rr = 1e9;
    trplet(Node *par, int lr, int rr)
    {
        this->par = par;
        this->lr = lr;
        this->rr = rr;
    }
};
Node *constructBst(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    queue<trplet> q;
    Node *treeRoot = new Node(arr[0]);
    trplet lft = trplet(treeRoot, -1e9, arr[0]);
    trplet rgt = trplet(treeRoot, arr[0], 1e9);
    q.push(lft);
    q.push(rgt);
    int i = 1;

    while (i < n && !q.empty())
    {
        trplet rootTrp = q.front();
        q.pop();
        Node *rootNode = rootTrp.par;
        int rootLr = rootTrp.lr;
        int rootRr = rootTrp.rr;
        if (arr[i] <= rootLr or arr[i] >= rootRr)
            continue;
        Node *childNode = new Node(arr[i]);
        i++;
        if (childNode->data < rootNode->data)
        {
            rootNode->left = childNode;
        }
        else
        {
            rootNode->right = childNode;
        }
        trplet leftTrp = trplet(childNode, rootLr, childNode->data);
        trplet rightTrp = trplet(childNode, childNode->data, rootRr);
        q.push(leftTrp);
        q.push(rightTrp);
    }
    return treeRoot;
}

int main()
{
    return 0;
}