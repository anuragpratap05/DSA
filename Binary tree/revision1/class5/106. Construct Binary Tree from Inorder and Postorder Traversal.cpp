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

// sir ne alg method se krwaya hai
int idx;
TreeNode *buildTree_help(vector<int> &postorder, vector<int> &inorder, int s, int e)
{

    if (idx <0 or s > e)
    {
        return nullptr;
    }
    int i = s;
    while (postorder[idx] != inorder[i])
    {
        i++;
    }
    TreeNode *root = new TreeNode(inorder[i]);
    idx--;
    root->right = buildTree_help(postorder, inorder, i + 1, e);
    root->left = buildTree_help(postorder, inorder, s, i - 1);
    
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n=inorder.size();
    idx=n-1;
    return buildTree_help(postorder,inorder,0,n-1);

}

int main()
{
    return 0;
}