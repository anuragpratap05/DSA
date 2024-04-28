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
void level_order(Node *root,  vector<int> &sa)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        // cout << "level:" << level << "-->";
       // sa.clear();
        sa.push_back(q.front()->data);
        while (size--)
        {
            Node *rn = q.front();
            q.pop();
            // << rn->val;
            
            if (rn->left != nullptr)
            {
                q.push(rn->left);
            }
            if (rn->right != nullptr)
            {
                q.push(rn->right);
            }
        }
        //ans.push_back(sa);
        level++;
    }
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int>ans;
    level_order(root,ans);
    return ans;
}

int main()
{
    return 0;
}