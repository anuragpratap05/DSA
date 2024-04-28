#include<bits/stdc++.h>
using namespace std;

// //testcase
//                       3
//                     /   \
//                    2     4         
//                  /
//                 3

                       
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
// sir ne alg method se krwaya hai

int idx=0;
TreeNode *buildTree_help(vector<int> &preorder,vector<int> &inorder,int s,int e)
{
    if(idx==preorder.size() or  s>e)
    {
        return nullptr;
    }
    int i=s;
    while(preorder[idx]!=inorder[i])
    {
        i++;
    }
    TreeNode* root=new TreeNode(inorder[i]);
    idx++;
    root->left=buildTree_help(preorder,inorder,s,i-1);
    root->right=buildTree_help(preorder,inorder,i+1,e);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n=preorder.size();
    return buildTree_help(preorder,inorder,0,n-1);
}

int main()
{
    return 0;
}