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

class Codec
{
public:
    // Encodes a tree to a single string.

    TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
    {
        while (root->right != nullptr and root->right != curr)
        {
            root = root->right;
        }
        return root;
    }
    string morris_preorder(TreeNode *root)
    {
        
        if (root == nullptr)
        {
            return {};
        }
        string ans="";
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            TreeNode *left = curr->left;
            if (left == nullptr)
            {
                ans+=to_string(curr->val);
                ans+=" ";
                curr = curr->right;
            }
            else
            {
                TreeNode *rmnode = rightmost_node(left, curr);
                if (rmnode->right == nullptr)
                {
                    rmnode->right = curr;
                    ans += to_string(curr->val);
                    ans += " ";
                    curr = curr->left;
                }
                else
                {
                    rmnode->right = nullptr;

                    curr = curr->right;
                }
            }
        }

        return ans;
    }

    string serialize(TreeNode *root)
    {
        string ans=morris_preorder(root);
        return ans;
    }
    int idx = 0;

    TreeNode *bstFromPreorder_help(vector<int> &preorder, int lr, int rr)
    {
        if (idx == preorder.size() or lr >= preorder[idx] or rr <= preorder[idx])
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        root->left = bstFromPreorder_help(preorder, lr, root->val);
        root->right = bstFromPreorder_help(preorder, root->val, rr);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return bstFromPreorder_help(preorder, -(1e9), 1e9);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream ss(data);
        vector<int>preorder;

        string word; 
        while (ss >> word)
        {
            preorder.push_back(stoi(word));
            
            
        }
        return bstFromPreorder(preorder);
    }
};

int main()
{
    return 0;
}