#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    map<int,vector<int>> m;

    queue<pair<int,TreeNode>> q;
    int minhl=0,maxhl=0;

    q.push({0,root});
    vector<vector<int>> ans;

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            
            pair<int,TreeNode> p=q.front();
            q.pop();
            int hl=p.first;
            TreeNode* node=p.second;
            minhl=min(minhl,hl);
            maxhl=max(maxhl,hl);
            m[hl].push_back(node->val);

            if(node->left!=nullptr)
            {
                q.push({hl-1,node->left});
            }
            if(node->right!=nullptr)
            {
                q.push({hl+1,node->right});
            }

        }
    }

    for(int i=minhl;i<=maxhl;i++)
    {
        ans.push_back(m[i]);
    }
    return ans;

}

int main()
{
    return 0;
}