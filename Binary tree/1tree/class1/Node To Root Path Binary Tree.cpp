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

vector<TreeNode *> nodeToRootPath(TreeNode *root, int data)
{
    //vector<TreeNode *> ans;

    if(root==nullptr)
    {
        return {};
    }
    if(root->val==data)
    {
        vector<TreeNode *> ans;
        ans.push_back(root);
        return ans;
    }

    vector<TreeNode *> left=nodeToRootPath(root->left,data);
    vector<TreeNode *> right = nodeToRootPath(root->right,data);

    if(left.size()==0 and right.size()==0)
    {
        return {};
    }
    else
    {
        if(left.size()!=0)
        {
            left.push_back(root);
            return left;
        }
        else{
            right.push_back(root);
            return right;
        }
        // ans.push_back(root);
        // return ans;
    }

}

vector<TreeNode *> nodeToRootPath2(TreeNode *root, int data, vector<TreeNode *> &ans)
{
    if (root == nullptr)
    {
        return {};
    }
    if (root->val == data)
    {
        //vector<TreeNode *> ans;
        ans.push_back(root);
        return ans;
    }

    vector<TreeNode *> left = nodeToRootPath2(root->left, data,ans);
    vector<TreeNode *> right = nodeToRootPath2(root->right, data,ans);

    if (left.size() == 0 and right.size() == 0)
    {
        return {};
    }
    else
    {
        // if (left.size() != 0)
        // {
        //     left.push_back(root);
        //     return left;
        // }
        // else
        // {
        //     right.push_back(root);
        //     return right;
        // }
        ans.push_back(root);
        return ans;
    }
}

int main()
{
    return 0;
}