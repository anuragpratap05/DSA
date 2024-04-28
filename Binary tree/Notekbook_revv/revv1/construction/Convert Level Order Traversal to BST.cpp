#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
    }
};

class Trplet
{
public:
    Node *par;
    int lr, rr;
    Trplet(Node *par, int lr, int rr)
    {
        this->par = par;
        this->lr = lr;
        this->rr = rr;
    }
};

int idx = 0;

Node *constructBst(int arr[], int n)
{
    queue<Trplet> q;
    Node *root = new Node(arr[idx++]);
    q.push(Trplet(root, -1e9, root->data));
    q.push(Trplet(root, root->data, 1e9));

    while (!q.empty())
    {
        Trplet t = q.front();
        q.pop();

        if (idx >= n or arr[idx] <= t.lr or arr[idx] >= t.rr)
            continue;
        Node *child = new Node(arr[idx++]);
        Node *par = t.par;

        if (child->data < par->data)
            par->left = child;
        else
            par->right = child;

        q.push(Trplet(child, t.lr, child->data));
        q.push(Trplet(child, child->data, t.rr));
    }
    return root;
}

int main()
{
    return 0;
}