#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
    this->val = val;
    }
};





TreeNode *constructFromInOrder_help(vector<int> &in,int s,int e)
{
    if(s>e){
        return nullptr;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(in[mid]);
    root->left=constructFromInOrder_help(in,s,mid-1);
    root->right=constructFromInOrder_help(in,mid+1,e);
    return root;


    
}

TreeNode *constructFromInOrder(vector<int> &in)
{
    
    int n=in.size();
    return constructFromInOrder_help(in,0,n-1);
}   

int main()
{
    return 0;
}