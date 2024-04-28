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

class p
{
public:
    int m_su_sf = -2000;
    int m_pa = 0;
};
p maxPathSum_help(TreeNode *root)
{
    if(root==nullptr)
    {
        p x;
        return x;
    }
    p left = maxPathSum_help(root->left);
    p right = maxPathSum_help(root->right);

    p myp;
    myp.m_su_sf = max(max(left.m_su_sf, right.m_su_sf), (left.m_pa + right.m_pa) + root->val);
    myp.m_su_sf = max(myp.m_su_sf, max(left.m_pa + root->val, right.m_pa + root->val));
    myp.m_su_sf = max(myp.m_su_sf, root->val);

    myp.m_pa = max(max(left.m_pa, right.m_pa) + root->val, root->val);
    return myp;
}
int maxPathSum(TreeNode *root)
{
    return maxPathSum_help(root).m_su_sf;
}

int main()
{
    return 0;
}