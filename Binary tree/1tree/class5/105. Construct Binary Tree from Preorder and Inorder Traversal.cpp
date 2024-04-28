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

TreeNode *buildTree2(vector<int> &preorder,int psi,int pei, vector<int> &inorder,int isi,int iei)
{
    if(psi>pei)
    {
        return nullptr;
    }
    int rootval=preorder[psi];
    int idx=isi;
    while(inorder[idx]!=rootval)
    {
        idx++;
    }
    int elements=idx-isi;
    TreeNode* root=new TreeNode(rootval);
    root->left=buildTree2(preorder,psi+1,psi+elements,inorder,isi,idx-1);
    root->right = buildTree2(preorder, psi + elements+ 1, pei, inorder, idx+1,iei);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree2(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1);
}

int main()
{
    return 0;
}