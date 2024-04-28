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
int ans=0;
int minCameraCover2(TreeNode *root)
{
    if(root==nullptr)
    {
        return 1;
    }
    int lc=minCameraCover2(root->left);
    int rc=minCameraCover2(root->right);
    if(lc==-1 or rc==-1)
    {
        ans++;
        return 0;
    }
    if(lc==0 or rc==0)
    {
        return 1;
    }
    return -1;
}

int minCameraCover(TreeNode *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    if (minCameraCover2(root)==-1)
    {
        ans++;
    }
    return ans;
}

int main()
{
    return 0;
}