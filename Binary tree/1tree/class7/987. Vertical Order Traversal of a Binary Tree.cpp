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

void level_order(TreeNode *root, vector<vector<pair<int, int>>> &ans, int level)
{
    queue<pair<TreeNode *, int>> q;
    q.push({root, level});
    int lev=0;
    while (!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *rn = p.first;
            int c_level = p.second;

            ans[c_level].push_back({lev, rn->val});
            if (rn->left != nullptr)
            {
                q.push({rn->left, c_level - 1});
            }
            if (rn->right != nullptr)
            {
                q.push({rn->right, c_level + 1});
            }
        }
        lev++;
       
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
void sort_pair(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first; });
    // display2(vec);
}
// Function to find the vertical width of a Binary Tree.
pair<int, int> verticalWidth(TreeNode *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    vector<int> vec(2, 0);
    width(root, 0, vec);
    int size = (vec[1] - vec[0]) + 1;
    int minval = vec[0];
    return {size, minval};
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // cout<<"aya";
    pair<int, int> p = verticalWidth(root);
    // cout<<"aya";
    int size = p.first;
    int minval = p.second;

    vector<vector<pair<int, int>>> ans(size, vector<pair<int, int>>());

    level_order(root, ans, abs(minval));
    for (vector<pair<int, int>> &vec : ans)
    {
        if (vec.size() > 1)
        {
            sort_pair(vec);
        }
    }
    vector<vector<int>> final(size,vector<int>());
    for(int i=0;i<ans.size();i++)
    {
        vector<pair<int,int>>& vec=ans[i];
        for(pair<int,int> p:vec)
        {
            final[i].push_back(p.second);
        }
    }
    return final;
}

int main()
{
    return 0;
}