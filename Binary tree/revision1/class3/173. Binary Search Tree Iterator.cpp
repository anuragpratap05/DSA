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
    TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
    {
        while (root->right != nullptr and root->right != curr)
        {
            root = root->right;
        }
        return root;
    }
    TreeNode *curr;
    TreeNode *l;
    BSTIterator(TreeNode *root)
    {
        curr = root;
        while (curr->left != nullptr)
        {
            l = curr->left;
            TreeNode *rmnode = rightmost_node(l, curr);
            rmnode->right = curr;
            curr = curr->left;
        }
    }

    int next()
    {
        int val;
        while (curr != nullptr)
        {
            l = curr->left;
            if (l == nullptr)
            {
                // ans.push_back(curr->val);
                val = curr->val;
                curr = curr->right;
                break;
            }
            else
            {
                TreeNode *rmnode = rightmost_node(l, curr);
                if (rmnode->right == nullptr)
                {
                    rmnode->right = curr;
                    curr = curr->left;
                }
                else
                {
                    rmnode->right = nullptr;
                    // ans.push_back(curr->val);
                    val = curr->val;
                    curr = curr->right;
                    break;
                }
            }
        }
        return val;
    }

    bool hasNext()
    {
        if (curr == nullptr)
        {
            return false;
        }
        return true;
    }
};

// Method2
class BSTIterator_
{
public:
    stack<TreeNode *> st;
    BSTIterator_(TreeNode *root)
    {

        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }
    void fillit(TreeNode *root)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }
    int next()
    {
        TreeNode *rmnode = st.top();
        st.pop();
        fillit(rmnode->right);
        return rmnode->val;
    }

    bool hasNext()
    {
        return st.size();
    }
};

int main()
{
    return 0;
}