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
    int n = s.length();
    int i = 0;
    stack<char> st;
    while (n--)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.size()==0)
            {
                return false;
            }
            else if ((s[i] == ')' and st.top() == '(') or (s[i] == '}' and st.top() == '{') or (s[i] == ']' and st.top() == '['))
            {
                st.pop();
            }
            else{
                return false;
            }
        }
        i++;
    }
    if(st.size()==0)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}