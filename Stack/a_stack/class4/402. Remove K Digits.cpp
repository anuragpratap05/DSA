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

string removeKdigits(string num, int k)
{
    int c=0;
    stack<int>st;
    int n=num.length();
    int i=0;
    while(i<n and c<k )
    {
        while(!st.empty() and st.top()>num[i]-'0' and c<k)
        {
            st.pop();
            c++;

        }
        st.push(num[i]-'0');
        i++;
    }
    while(!st.empty() and c<k)
    {
        st.pop();
        c++;
    }
    string ans="";
    while(!st.empty())
    {
        ans+=to_string(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    while(i<n)
    {
        ans+=num[i];
        i++;
    }
    return ans;
}

int main()
{
    return 0;
}