#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data=0;
    Node* left=NULL;
    Node* right=nullptr;

    Node(int data)
    {
        this->data=data;
    }
};

bool find(vector<int>& v,int ele,Node* root)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->data==ele)
    {
        v.push_back(ele);
        return true;
    }
    if(find(v,ele,root->left) or find(v,ele,root->right))
    {
        v.push_back(root->data);
        return true;
    }
    return false;

}

int main()
{
    vector<int>v;
    int ele=5;
    Node* root=new Node(3)
    find(v,ele,root);

}