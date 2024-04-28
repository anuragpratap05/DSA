#include <bits/stdc++.h>
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
    stack<pair<int, int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
            return;
        }
        int minEle = st.top().second;
        st.push({val, min(val, minEle)});
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