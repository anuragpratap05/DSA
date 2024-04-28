#include <bits/stdc++.h>
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

void print_k_down(TreeNode *root, int k, vector<vector<int>> &ans, TreeNode *block)
{
    if (root == nullptr or root == block)
    {
        return;
    }
    if (k == ans.size())
    {
        ans.push_back({});
    }

    ans[k].push_back(root->val);
    

    print_k_down(root->left, k + 1, ans, block);
    print_k_down(root->right, k + 1, ans, block);
}
int distanceK_btr_help(TreeNode *root, TreeNode *target,  vector<vector<int>> &ans)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root == target)
    {
        print_k_down(root, 0, ans, nullptr);
        return 1;
    }

    int lc = distanceK_btr_help(root->left, target, ans);
    if (lc != 0)
    {
        print_k_down(root, lc, ans, root->left);
        return lc + 1;
    }

    int rc = distanceK_btr_help(root->right, target,  ans);
    if (rc != 0)
    {
        print_k_down(root, rc, ans, root->right);
        return rc + 1;
    }
    return 0;
}

vector<vector<int>> burning_tree(TreeNode *root,TreeNode* target)
{
    vector<vector<int>>ans;
    distanceK_btr_help(root,target,ans);
    for(auto& vec:ans)
    {
        for(int e:vec)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    return 0;
}