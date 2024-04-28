#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            if (st.top()!=-1 and s[st.top()] == '(')
            {
                st.pop();
                maxLen = max(maxLen, i - st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return maxLen;
}

int main()
{
    return 0;
}