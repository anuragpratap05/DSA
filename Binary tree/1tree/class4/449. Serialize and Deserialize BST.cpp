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
TreeNode *construct(vector<int> &preorder, int lr, int rr, vector<int> &vec)
{
    int i = vec[0];
    int ele;
    if (i < preorder.size())
    {
        ele = preorder[i];
    }
    if (ele < lr or ele > rr or i == preorder.size())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(ele);
    vec[0]++;
    root->left = construct(preorder, lr, ele, vec);
    root->right = construct(preorder, ele, rr, vec);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> vec = {0};
    return construct(preorder, -1e9, 1e9, vec);
}
void serializeit(TreeNode *root, string &str)
{
    if(root==nullptr)
    {
        return ;
    }
    str+= (to_string(root->val))+" ";
    serializeit(root->left,str);
    serializeit(root->right, str);

    return;
}
string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }
    string s="";
    serializeit(root,s);
    return s;

}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if(data=="")
    {
        return nullptr;
    }
    vector<int>preorder;
    istringstream ss(data);

    string word;

    while (ss >> word)
    {
        int val=stoi(word);
        preorder.push_back(val);
    }

   return bstFromPreorder(preorder);
}

int main()
{
    return 0;
}