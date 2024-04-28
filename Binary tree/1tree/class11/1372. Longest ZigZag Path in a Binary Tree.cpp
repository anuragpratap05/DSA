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
//{forward_slash,backward_slash,longest_zig_zag}
vector<int> longestZigZag2(TreeNode *root)
{
    if(root==nullptr)
    {
        return{-1,-1,-1};
    }
    vector<int> left=longestZigZag2(root->left);
    vector<int> right=longestZigZag2(root->right);

    vector<int>myans(2);
    myans[0] = left[1] + 1;
    myans[1]=right[0]+1;
    myans[2]=max(max(myans[0],myans[1]),max(left[2],right[2]));
    return myans;
}

int longestZigZag(TreeNode *root)
{
    return longestZigZag2(root)[2];
}

int main()
{
    return 0;
}