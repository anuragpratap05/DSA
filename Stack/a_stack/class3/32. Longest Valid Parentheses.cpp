#include <bits/stdc++.h>
using namespace std;


int longestValidParentheses(string s)
{
    int n = s.length();
    int i = 0;
    stack<int> st;
    while (i<n)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (st.size() == 0)
            {

                st.push(i);
            }
            else if (s[st.top()] == '(')
            {

                st.pop();
            }
            else
            {

                st.push(i);
            }
        }
        i++;
    }
    if(st.size()==0)
    {
        return n;
    }
    int maxi=0,ans=0;
    i=n-1;
    while(!st.empty())
    {
        if(i==st.top())
        {
            ans=0;
            st.pop();
        }
        else{
            ans++;
            maxi=max(maxi,ans);
        }
        i--;
    }
    return max(maxi,i+1);

}
int longestValidParentheses2(string s)
{
    int n=s.length();
    int i=0;
    stack<int>st;
    st.push(-1);
    int len=0;
    while(i<n)
    {
        if(st.top()!=-1 and s[st.top()]=='(' and s[i]==')')
        {
            st.pop();
            len=max(len,i-st.top());
        }
        else{
            st.push(i);
        }
        i++;
    }
    return len;
}
int main()
{
    return 0;
}