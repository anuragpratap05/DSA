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

vector<int> vec;

void shadow(Node *root, int x)
{
    if (root == nullptr)
    {
        return;
    }
    vec[0] = min(vec[0], x);
    vec[1] = max(vec[1], x);
    shadow(root->left, x - 1);
    shadow(root->right, x + 1);
}

void dfs(Node *root, int k, vector<vector<int>> &ans)
{
    if(root==nullptr)
    {
        return;
    }
    if(k==ans.size())
    {
        ans.push_back({});
    }
    ans[k].push_back(root->data);
    
    dfs(root->left, k + 1, ans);
    dfs(root->right, k , ans);

}

vector<int> diagonal(Node *root)
{

    vector<vector<int>> ans;
    dfs(root, 0, ans);
    vector<int> final;
    for(auto& vec:ans)
    {
        for(int e:vec)
        {
            final.push_back(e);
        }
    }
    return final;
}

int main()
{
    return 0;
}