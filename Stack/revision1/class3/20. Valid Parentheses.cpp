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

bool isValid(string s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' or ch == '{' or ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if (ch == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                    return false;
            }
            else if (ch == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                    return false;
            }
            else
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    return 0;
}