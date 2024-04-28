#include<bits/stdc++.h>
using namespace std;

bool node_To_root(TreeNode* root, TreeNode* target,vector<TreeNode*>& ans)
{
    if(root ==NULL)
    {
        return false;
    }
    if(root==target)
    {
        ans.push_back(root);
        return true;
    }



    

    bool left=node_To_root(root->left,target,ans);
    if(left)
    {
        ans.push_back(root);
        return true;
    }
    bool right=node_To_root(root->right,target,ans);
    if(right)
    {
        ans.push_back(root);
        return true;
    }
    return false;


}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{

    vector<TreeNode*> v1;
    vector<TreeNode*> v2;
    node_To_root(root,p,v1);
    node_To_root(root,q,v2);

    for(auto ele:v1)
    {
        cout<<ele;
    }
    cout<<endl;
    for(auto ele:v2)
    {
        cout<<ele;
    }

    int n=v1.size();
    int m=v2.size();

    reverse(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());

    for(int i=0;i<min(n,m);i++)
    {
        if(v1[i]->val != v2[i]->val)
        {
            return v1[i-1];
            break;
        }
    }
    if(n<m)
    {
        return v1[n-1];
    }
    else{
        return v2[m-1];
    }

      
}


TreeNode* lcanode=NULL;
bool lca(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr)
    {
        return false;
    }
    bool self=(root==p or root==q);

    bool left=lca(root->left,p,q);
    bool right=lca(root->right,p,q);

    if((self and left) or (self and right) or (left and right))
    {
        lcanode=root;
    }
    return (self or left or right);

}

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    lca(root,p,q);
    return lcanode;
}

int main()
{

}