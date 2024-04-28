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
TreeNode *constructFromPrePost2(vector<int> &preorder,int presi,int preei, vector<int> &postorder,int possi,int posei)
{
    if(presi>preei)
    {
        return nullptr;
    }
    TreeNode* root=new TreeNode(preorder[presi]);
    if(presi==preei)
    {
        return root;
    }
    int idx=possi;
    while(postorder[idx]!=preorder[presi+1])
    {
        idx++;
    }
    int no=idx-possi;

    root->left = constructFromPrePost2(preorder, presi + 1, presi + 1+no,postorder,possi,idx);
    root->right = constructFromPrePost2(preorder, presi + 2+no, preei, postorder, idx+1, posei-1);
    return root;
}
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    return constructFromPrePost2(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
}

int main()
{
    return 0;
}