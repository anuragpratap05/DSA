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

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        pair<int, int> p = {val, val};
        if(!st.empty())
        {
            p.second = min(val, st.top().second);

        }
        st.push(p);
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    return 0;
}