#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' or ch == '{' or ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;
            char openningBrace = st.top();
            st.pop();
            if (ch == ')')
            {
                if (openningBrace != '(')
                    return false;
            }
            else if (ch == '}')
            {
                if (openningBrace != '{')
                    return false;
            }
            else
            {
                if (openningBrace != '[')
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    return 0;
}