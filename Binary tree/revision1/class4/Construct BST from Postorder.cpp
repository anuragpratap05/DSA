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

Node *bstFromPreorder_help(vector<int> &preorder, int lr, int rr, vector<int> &idx)
{
    if (idx[0] < 0 or lr >= preorder[idx[0]] or rr <= preorder[idx[0]])
    {
        return nullptr;
    }
    Node *root = new Node(preorder[idx[0]]);
    idx[0]--;
    root->right = bstFromPreorder_help(preorder, root->data, rr, idx);
    root->left = bstFromPreorder_help(preorder, lr, root->data,idx);
    
    return root;
}

Node *constructTree(int post[], int size)
{
    vector<int> postorder;
    vector<int> idx(1, size - 1);
    for (int i = 0; i < size; i++)
    {
        postorder.push_back(post[i]);
    }
    return bstFromPreorder_help(postorder,-(1e9),1e9,idx);
}

int main()
{
    return 0;
}