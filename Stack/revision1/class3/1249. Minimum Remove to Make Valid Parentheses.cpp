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

string minRemoveToMakeValid(string s)
{
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if(ch== '(' or ch== ')')
        {
            if(ch == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() and s[st.top()]== '(')
                {
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
    }
    string ans = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if(!st.empty() and st.top()==i)
        {
            st.pop();
        }
        else{
            ans += s[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}