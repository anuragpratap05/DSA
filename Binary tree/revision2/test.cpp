// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#include <bits/stdc++.h>
using namespace std;

bool valiodateSequence(string str)
{
    if (str.size() == 0)
        return true;
    stack<char> st;
    for (char ch : str)
    {
        if (ch == '(' or ch == '{' or ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (ch == '}')
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
    }
    return st.size() == 0;
}

int main()
{
    string str = "(()){{}[]";

    bool isValid = valiodateSequence(str);
    if (isValid)
    {
        cout << "String is valid!";
    }
    else
    {
        cout << "Invalid String";
    }

    return 0;
}