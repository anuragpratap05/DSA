#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
vector<vector<int>> levelOrder_help(Node *root)
{
    int level = 0;
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }
    while (!q.empty())
    {
        ans.push_back({});
        int size = q.size();
        while (size--)
        {
            Node *rn = q.front();
            q.pop();
            ans[level].push_back(rn->val);
            for (auto child : rn->children)
            {
                q.push(child);
            }
        }
        level++;
    }
    return ans;
}

vector<vector<int>> levelOrder(Node *root)
{
    return levelOrder_help(root);
}

int main()
{
    return 0;
}