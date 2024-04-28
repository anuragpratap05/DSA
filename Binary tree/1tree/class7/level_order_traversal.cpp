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

void level_order(TreeNode* root)
{
    if(root==nullptr)
    {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        cout<<"level:"<<level<<"-->";
        while(size--)
        {
            TreeNode* rn=q.front();
            q.pop();
            cout<<rn->val;
            if(rn->left!=nullptr)
            {
                q.push(rn->left);
            }
            if (rn->right != nullptr)
            {
                q.push(rn->right);
            }
        }
        level++;
    }
}

int main()
{
    return 0;
}