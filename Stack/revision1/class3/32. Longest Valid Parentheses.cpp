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

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int n = s.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if(ch =='(')
        {
            st.push(i);
        }
        else
        {
            if(st.top()!=-1 and s[st.top()]=='(')
            {
                st.pop();
                int c_len = i - st.top();
                len = max(len, c_len);
            }
            else
                st.push(i);
        }
    }
    return len;
}

int main()
{
    return 0;
}