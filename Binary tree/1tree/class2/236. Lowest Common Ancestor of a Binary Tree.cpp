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

vector<TreeNode *> root_to_node(TreeNode *root, TreeNode *tar)
{
    if(root==nullptr)
    {
        return {};
    }
    if(root==tar)
    {
        return {root};

    }
    vector<TreeNode *> l=root_to_node(root->left,tar);
    vector<TreeNode *> r = root_to_node(root->right, tar);

    if(l.size()!=0)
    {
        l.push_back(root);
        return l;
    }
    if(r.size()!=0)
    {
        r.push_back(root);
        return r;
    }
    return {};
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode * >vec1=root_to_node(root,p);
    vector<TreeNode *> vec2 = root_to_node(root, q);

    


    int n=vec1.size();
    int m=vec2.size();

    int i=0;int j=0;
    while(i<n and j<m)
    {
        if(vec1[i]==vec2[j])
        {
            return vec1[i];
        }
        i++;
        j++;
    }
    return nullptr;
}
TreeNode* lcanode=nullptr;
bool lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==nullptr)
    {
        return false;
    }

    bool self= (root==p or root==q);
    
    bool left=lca(root->left,p,q);
    if (lcanode != nullptr)
    {
        return true;
    }
    if(left and self)
    {
        lcanode=root;
        return true;
    }
    bool right = lca(root->right, p, q);
    if (lcanode != nullptr)
    {
        return true;
    }
    if((self and right) or (left and right))
    {
        lcanode=root;
        return true;
    }
    return self or left or right;
}

    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{

}

int main()
{
    return 0;
}