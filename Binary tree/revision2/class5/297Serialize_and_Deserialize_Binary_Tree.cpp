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

    void getTreeString(TreeNode *root, string &str)
    {
        if (root == nullptr)
        {
            str += "# ";
            return;
        }
        str += to_string(root->val) + " ";
        getTreeString(root->left, str);
        getTreeString(root->right, str);
    }

    string serialize(TreeNode *root)
    {
        string str = "";
        getTreeString(root, str);
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

    // Decodes your encoded data to tree.
    TreeNode *constructFromPreorder(vector<string> &preorder)
    {
        if (preorder[idx++] == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(preorder[idx++]));
        root->left = constructFromPreorder(preorder);
        root->right = constructFromPreorder(preorder);
        return root;
    }
    TreeNode *deserialize(string data)
    {
        vector<string> preorder = splitOnSpaces(data);
        return constructFromPreorder(preorder);
    }
};
int main()
{
    string data = "1 2 # # 3 4 # # 15 # #";

    cout << data[16];
    return 0;
}