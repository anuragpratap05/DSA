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
    void serialize_help(TreeNode *root, string &str)
    {
        if (root == nullptr)
        {
            str += "# ";
            return;
        }
        str += to_string(root->val);
        str += " ";
        serialize_help(root->left, str);
        serialize_help(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str = "";
        serialize_help(root, str);
        return str;
    }
    int idx = 0;
    TreeNode *construct(vector<string>& s)
    {
        if (idx >= s.size() or s[idx] == "#")
        {
            idx++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(s[idx]));
        idx ++;
        root->left = construct(s);
        root->right = construct(s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream ss(data);
        string word;
        vector<string> vec;
        while (ss >> word)
        {
            vec.push_back(word);
        }
        return construct(vec);
    }
    
};

class Codec_
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str="";
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* rn=q.front();
            q.pop();
            if(rn==nullptr)
            {
                str+="# ";
                continue;
            }
            str+=to_string(root->val);
            str+=" ";
            q.push(root->left);
            q.push(root->right);

        }
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream ss(data);
        string word;
        vector<string> vec;
        while (ss >> word)
        {
            vec.push_back(word);
        }
        int val=0;
        
        for(int i=0;i<vec.size();i++)
        {
            int idx=i+val;
            TreeNode *root = new TreeNode(stoi(vec[idx]));

        }
        return NULL;
    }
};

int main()
{
    return 0;
}