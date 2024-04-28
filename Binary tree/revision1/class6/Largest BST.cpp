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

class pair_
{
public:
    int mini;
    int maxi;
    bool is_bst;
    int size;
};

pair_ largestBst_help(Node *root)
{
    if(root==nullptr)
    {
        pair_ base;
        base.mini=1e8;
        base.maxi=-(1e8);
        base.is_bst=true;
        base.size=0;
        return base;
    }
    pair_ left=largestBst_help(root->left);
    pair_ right=largestBst_help(root->right);
    pair_ mypair;
    if(left.is_bst and right.is_bst and left.maxi<root->data and right.mini>root->data)
    {
        mypair.is_bst=true;
        mypair.mini=min(left.mini,root->data);
        mypair.maxi=max(right.maxi,root->data);
        mypair.size=(left.size+right.size)+1;
    }
    else
    {
        mypair.is_bst = false;
        mypair.size = max(left.size , right.size) ;
    }
    return mypair;
}

int largestBst(Node *root)
{
    return largestBst_help(root).size;
}

int main()
{
    return 0;
}