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
TreeNode *buildTree2(vector<int> &inorder,int isi,int iei, vector<int> &postorder,int psi,int pei)
{
    if(psi>pei)
    {
        return nullptr;
    }
    int rootval=postorder[pei];
    int idx=isi;
    while(inorder[idx]!=rootval)
    {
        idx++;
    }
    int no=idx-isi;
    TreeNode* root=new TreeNode(rootval);
    root->left=buildTree2(inorder,isi,idx-1,postorder,psi,psi+no-1);
    root->right = buildTree2(inorder, idx+1, iei, postorder, no+psi, pei - 1);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTree2(inorder, 0, inorder.size()-1,postorder,0,postorder.size()-1);
}

int main()
{
    return 0;
}