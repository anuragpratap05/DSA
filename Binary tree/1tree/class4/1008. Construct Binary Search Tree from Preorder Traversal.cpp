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

TreeNode *construct(vector<int> &preorder, int lr, int rr, vector<int> &vec)
{
    int i=vec[0];
    int ele;
    if(i<preorder.size())
    {
         ele=preorder[i];
    }
    if (ele < lr or ele > rr or i == preorder.size())
    {
        return nullptr;
    }
    TreeNode* root=new TreeNode(ele);
    vec[0]++;
    root->left=construct(preorder,lr,ele,vec);
    root->right = construct(preorder, ele, rr, vec);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> vec={0};
    return construct(preorder,-1e9,1e9,vec);

}

int main()
{
    return 0;
}