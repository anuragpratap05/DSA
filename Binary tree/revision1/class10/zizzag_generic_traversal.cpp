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
vector<vector<int>> levelOrder_zigzag(Node *root)
{
    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    int level = 0;
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int size = q.size();
        ans.push_back({});
        while (size--)
        {
            Node *rn = q.front();
            q.pop();
            ans[level].push_back(rn->val);
            if(level%2!=0)
            {
                for (int i = rn->children.size() - 1; i >= 0;i--)
                {
                    st.push(rn->children[i]);
                }
            }
            else
            {
                for(auto child:rn->children)
                {
                    st.push(child);
                }
            }
        }
        while(!st.empty())
        {
            Node *rn = st.top();
            st.pop();
            q.push(rn);
        }
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}