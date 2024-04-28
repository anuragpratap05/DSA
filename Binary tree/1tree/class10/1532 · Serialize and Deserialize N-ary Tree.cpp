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

struct DirectedGraphNode
{
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x){};
    
};
string serialize(vector<DirectedGraphNode *> &nodes)
{
    
}
vector<DirectedGraphNode *> deserialize(string &data)
{
}

int main()
{
    return 0;
}