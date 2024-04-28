#include<bits/stdc++.h>
using namespace std;

void width(TreeNode* root,int hl,vector<int>& vec)
{
    if(root==nullptr)
    {
        return;
    }
    vec[0]=min(vec[0],hl);
    vec[1]=max(vec[1],hl);
    width(root->left,hl-1,vec);
    width(root->right,hl+1,vec);
}


int widthOfBinaryTree(TreeNode* root)
{
    vector<int> vec(2,0);
    width(root,0,vec); 
    return vec[1]-vec[0]+1;       
}

int main()
{
    return 0;
}