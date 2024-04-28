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
// using level order traversal
string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }
    queue<TreeNode *> q;
    q.push(root);
    string s = "";
    while (!q.empty())
    {
        TreeNode *rn = q.front();
        q.pop();
        s += (rn == nullptr ? "#" : to_string(rn->val));
        s += " ";
        if (rn == nullptr)
        {
            continue;
        }
        q.push(rn->left);
        q.push(rn->right);
    }
    return s;
}

TreeNode *construct(vector<string> &str)
{
    int n = str.size();
    if (n == 0)
    {
        return NULL;
    }
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(str[0]));

    q.push(root);
    int idx = 1;
    while (!q.empty())
    {
        TreeNode *rn = q.front();
        q.pop();

        if (str[idx] != "#")
        {
            TreeNode *lc = new TreeNode(stoi(str[idx]));
            rn->left = lc;
            q.push(lc);
        }
        idx++;

        if (str[idx] != "#")
        {
            TreeNode *rc = new TreeNode(stoi(str[idx]));
            rn->right = rc;
            q.push(rc);
        }
        idx++;
    }
    return root;
}
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data == "")
    {
        return NULL;
    }
    istringstream ss(data);
    vector<string> str;
    string word;

    while (ss >> word)
    {
        str.push_back(word);
    }
    return construct(str);
    // for(auto x:str)
    // {
    //     cout<<x<<endl;
    // }
    // return NULL;
}

int main()
{
    return 0;
}