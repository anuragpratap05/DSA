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

class BSTIterator
{
public:
    TreeNode *rightMostNode(TreeNode *root, TreeNode *curr)
    {
        if (root == nullptr)
            return root;
        while (root->right != nullptr and root->right != curr)
            root = root->right;

        return root;
    }
    TreeNode *curr;

    void goToExtremeLeft()
    {
        while (this->curr->left != nullptr)
        {
            TreeNode *l = this->curr->left;
            TreeNode *rmNode = this->rightMostNode(l, curr);
            rmNode->right = curr;
            this->curr = this->curr->left;
        }
    }

    BSTIterator(TreeNode *root)
    {
        this->curr = root;
        this->goToExtremeLeft();
    }

    int next()
    {
        TreeNode *l = this->curr->left;
        int ans;
        if (l == nullptr)
        {
            ans = this->curr->val;
            this->curr = this->curr->right;
        }
        else
        {
            TreeNode *rmNode = this->rightMostNode(l, curr);
            if (rmNode->right == nullptr)
            {
                this->goToExtremeLeft();
                ans = this->curr->val;
                this->curr = this->curr->right;
            }
            else
            {
                rmNode->right = nullptr;
                ans = this->curr->val;
                this->curr = this->curr->right;
            }
        }
        return ans;
    }

    bool hasNext()
    {
        return this->curr != nullptr;
    }
};

class BSTIterator2
{
public:
    stack<TreeNode *> st;
    void pushAllNodesOnLeft(TreeNode *curr)
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
    }
    BSTIterator2(TreeNode *root)
    {
        pushAllNodesOnLeft(root);
    }

    int next()
    {
        TreeNode *rnode = st.top();
        st.pop();
        pushAllNodesOnLeft(rnode->right);
        return rnode->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{
    return 0;
}