#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
    this->data = data;
    }
};

void help(Node *root, vector<int> &temp, vector<vector<int>>& ans)
{
    temp.push_back(root->data);
    if(root->left==nullptr and root->right==nullptr)
    {
        ans.push_back(temp);
        temp.pop_back();
        return ;
    }
    if(root->left!=nullptr)
    {
        help(root->left,temp,ans);
    }
    if (root->right != nullptr)
    {
        help(root->right, temp, ans);
    }
    temp.pop_back();
}

vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>>ans;
    vector<int>temp;
    help(root,temp,ans);
    return ans;
}

int main()
{
    return 0;
}