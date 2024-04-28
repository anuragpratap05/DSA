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

void serializeit_pre(TreeNode *root, string &str)
{
    if (root == nullptr)
    {
        str += "# ";
        return;
    }
    str += (to_string(root->val)) + " ";
    serializeit_pre(root->left, str);
    serializeit_pre(root->right, str);

    return;
}

string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }

    string s = "";
    serializeit_pre(root, s);

    return s;
}
int idx = 0;
TreeNode *construct(vector<string> &s)
{
    if (idx >= s.size() or s[idx] == "#")
    {
        idx++;
        return nullptr;
    }
    int rootval = stoi(s[idx]);
    idx++;
    TreeNode *root = new TreeNode(rootval);
    root->left = construct(s);
    root->right = construct(s);
    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    idx = 0;
    if (data == "")
    {
        return nullptr;
    }

    istringstream ss(data);
    vector<string> str;
    string word;

    while (ss >> word)
    {
        str.push_back(word);
    }
    TreeNode *myroot = construct(str);

    return myroot;
}

int main()
{
    return 0;
}