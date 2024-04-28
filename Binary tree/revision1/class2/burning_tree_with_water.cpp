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

void print_k_down(TreeNode *root, int k, vector<vector<int>> &ans, TreeNode *block, unordered_set<int> &waterset)
{
    if (root == nullptr or root == block or waterset.find(root->val)!=waterset.end())
    {
        return;
    }
    if (k == ans.size())
    {
        ans.push_back({});
    }

    ans[k].push_back(root->val);

    print_k_down(root->left, k + 1, ans, block,waterset);
    print_k_down(root->right, k + 1, ans, block,waterset);
}
int distanceK_btr_help(TreeNode *root, TreeNode *target, vector<vector<int>> &ans, unordered_set<int> &waterset)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root == target)
    {
        if (waterset.find(root->val) == waterset.end())
        {
            print_k_down(root, 0, ans, nullptr, waterset);
            return 1;
        }
        return -1;
            
    }

    int lc = distanceK_btr_help(root->left, target, ans, waterset);
    if (lc != 0)
    {
        if(lc!=-1 and waterset.find(root->val)==waterset.end())
        {
            print_k_down(root, lc, ans, root->left, waterset);
            return lc + 1;
        }
        return -1;
        
    }

    int rc = distanceK_btr_help(root->right, target, ans, waterset);
    if (rc != 0)
    {
        if (rc != -1 and waterset.find(root->val) == waterset.end())
        {
            print_k_down(root, rc, ans, root->right, waterset);
            return rc + 1;
        }
        return -1;
        
    }
    return 0;
}

vector<vector<int>> burning_tree(TreeNode *root, TreeNode *target,unordered_set<int>& waterset)
{
    vector<vector<int>> ans;
    cout<<distanceK_btr_help(root, target, ans,waterset);
    for (auto &vec : ans)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    return 0;
}