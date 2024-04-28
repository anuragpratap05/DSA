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

int i = 0;
void verifyPreorder(vector<int> &preorder, int lr, int rr)
{
    if (i >= preorder.size() or lr >= preorder[i] or rr <= preorder[i])
        return;
    int rootVal = preorder[i];
    i++;
    verifyPreorder(preorder, lr, rootVal);
    verifyPreorder(preorder, rootVal, rr);
    return;
}

bool verifyPreorder(vector<int> &preorder)
{
    verifyPreorder(preorder, -1e9, 1e9);
    return i >= preorder.size();
}

int main()
{
    return 0;
}