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

vector<vector<int>> Paths(Node *root)
{
    if(root==nullptr)
    {
        return {};
    }
    if(root->left==nullptr and root->right==nullptr)
    {
        return {{root->data}};
    }

    vector<vector<int>>left=Paths(root->left);
    vector<vector<int>>right=Paths(root->right);

    vector<vector<int>>myans;
    for(auto& vec:left)
    {
        vec.push_back(root->data);
        myans.push_back(vec);
    }

    for (auto &vec : right)
    {
        vec.push_back(root->data);
        myans.push_back(vec);
    }
    return myans;
}

int main()
{
    return 0;
}