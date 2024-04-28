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

int startingIdxOfElesToRightOfRoot(vector<int> &preorder, vector<int> &postorder, int s, int e, int rootEle)
{
    int i = 0;
    while (postorder[i] != rootEle)
        i++;
    i--;

    int eleJustRightToRoot = postorder[i];

    int itr = s + 1;
    while (itr <= e and preorder[itr] != eleJustRightToRoot)
        itr++;
    return itr;
}

TreeNode *constructFromPrePostHeper(vector<int> &preorder, vector<int> &postorder, int s, int e)
{
    if (s > e)
        return nullptr;
    if (s == e)
        return new TreeNode(preorder[s]);

    TreeNode *root = new TreeNode(preorder[s]);

    int rightTreeStartingIdx = startingIdxOfElesToRightOfRoot(preorder, postorder, s, e, root->val);
    int leftTreeEndingIdx = rightTreeStartingIdx - 1;

    root->left = constructFromPrePostHeper(preorder, postorder, s + 1, leftTreeEndingIdx);
    root->right = constructFromPrePostHeper(preorder, postorder, rightTreeStartingIdx, e);
    return root;
}

int idx = 0;

TreeNode *constructFromPrePost2(vector<int> &preorder, vector<int> &postorder, int s, int e)
{
    if (s >= e)
        return s > e ? nullptr : new TreeNode(preorder[idx++]);

    TreeNode *root = new TreeNode(preorder[idx++]);

    int i = s;
    while (postorder[i] != preorder[idx])
        i++;

    root->left = constructFromPrePost2(preorder, postorder, s, i);
    root->right = constructFromPrePost2(preorder, postorder, i + 1, e - 1);
    return root;
}

TreeNode *constructFromPrePost2(vector<int> &preorder, vector<int> &postorder)
{
    return constructFromPrePost2(preorder, postorder, 0, preorder.size() - 1);
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    return constructFromPrePostHeper(preorder, postorder, 0, preorder.size() - 1);
}

int main()
{
    return 0;
}