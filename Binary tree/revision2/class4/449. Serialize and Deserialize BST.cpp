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
    void serialize(TreeNode *root, string &str)
    {
        if (root == nullptr)
            return;
        str += to_string(root->val) + " ";
        serialize(root->left, str);
        serialize(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str = "";
        serialize(root, str);
        return str;
    }

    vector<string> splitOnSpaces(string str)
    {
        string s;

        stringstream ss(str);

        vector<string> v;

        while (getline(ss, s, ' '))
        {
            v.push_back(s);
        }

        return v;
    }

    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int lr, int rr)
    {
        if (idx >= preorder.size() or preorder[idx] <= lr or preorder[idx] >= rr)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        root->left = bstFromPreorder(preorder, lr, root->val);
        root->right = bstFromPreorder(preorder, root->val, rr);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return bstFromPreorder(preorder, -1e9, 1e9);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;
        vector<string> vec = splitOnSpaces(data);
        vector<int> preorder;
        for (string str : vec)
            preorder.push_back(stoi(str));

        return bstFromPreorder(preorder);
    }
};

int main()
{
    return 0;
}