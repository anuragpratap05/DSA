#include<bits/stdc++.h>
using namespace std;

// gfg
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

void level_order(TreeNode* root,vector<vector<int>>& ans,int level)
{
    queue<pair<TreeNode*,int>>q;
    q.push({root,level});
    while(!q.empty())
    {
        pair<TreeNode*,int>p=q.front();
        q.pop();
        TreeNode* rn=p.first;
        int c_level=p.second;

        ans[c_level].push_back(rn->val);
        if(rn->left!=nullptr)
        {
            q.push({rn->left,c_level-1});
        }
        if (rn->right != nullptr)
        {
            q.push({rn->right, c_level + 1});
        }
    }
}
void width(TreeNode *root, int idx, vector<int> &vec)
{
    if (root == nullptr)
    {
        return;
    }
    vec[0] = min(vec[0], idx);
    vec[1] = max(vec[1], idx);
    width(root->left, idx - 1, vec);
    width(root->right, idx + 1, vec);
    return;
}
// Function to find the vertical width of a Binary Tree.
pair<int,int> verticalWidth(TreeNode *root)
{
    if (root == NULL)
    {
        return {0,0};
    }
    vector<int> vec(2, 0);
    width(root, 0, vec);
    int size=(vec[1] - vec[0])+ 1;
    int minval=vec[0];
    return {size,minval};
}
vector<int> verticalOrder(TreeNode *root)
{
    pair<int, int> p = verticalWidth(root);

    int size=p.first;
    int minval=p.second;
    vector<vector<int>>ans(size,vector<int>());
    level_order(root,ans,abs(minval));
    vector<int>final;
    for(vector<int>& vec:ans)
    {
        for(int e:vec)
        {
            final.push_back(e);
        }
    }
    return final;
}

int main()
{
    return 0;
}