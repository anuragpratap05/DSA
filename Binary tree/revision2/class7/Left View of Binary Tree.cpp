#include <bits/stdc++.h>
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

vector<int> levelOrder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        ans.push_back(q.front()->data);
        while (size--)
        {
            Node *curRoot = q.front();
            q.pop();
            if (curRoot->left)
                q.push(curRoot->left);
            if (curRoot->right)
                q.push(curRoot->right);
        }
    }
    return ans;
}
vector<int> leftView(Node *root)
{
    return levelOrder(root);
}

int main()
{
    return 0;
}