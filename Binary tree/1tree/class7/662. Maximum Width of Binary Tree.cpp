#include<bits/stdc++.h>
using namespace std;

// nhi smjh aa rha
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
int level_order(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans=0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        ans=max(ans,size);
       // cout << "level:" << level << "-->";
        while (size--)
        {
            TreeNode *rn = q.front();
            q.pop();
            if(rn==nullptr or (rn->left==nullptr and rn->right==nullptr))
            {
                continue;
            }
           // cout << rn->val;
            
                q.push(rn->left);
            
                q.push(rn->right);
            
        }
        level++;
    }
    return ans;
}
int widthOfBinaryTree(TreeNode *root)
{
    return level_order(root);
}

int main()
{
    return 0;
}