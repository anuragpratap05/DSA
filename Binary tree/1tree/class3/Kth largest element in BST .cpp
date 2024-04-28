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
void fillit(Node *root, stack<Node *> &s)
{
    if (root == nullptr)
    {
        return;
    }
    s.push(root);
    fillit(root->left, s);
    return;
}

void isValidBST(Node *root,vector<int>& ans)
{
    stack<Node *> s;
    Node *c = root;
    while (c->left != nullptr)
    {
        s.push(c);
    }
    while (!s.empty())
    {
        Node *node = s.top();
        s.pop();
        ans.push_back(node->data);
        fillit(node->right, s);
    }
    
}
int kthLargest(Node *root, int K)
{
    vector<int>ans;
    isValidBST(root,ans);
    for(int i=ans.size();i>=0;i--)
    {
        K--;
        if(K==0)
        {
            return ans[i];
        }
    }
    return 0;
}

int main()
{
    return 0;
}