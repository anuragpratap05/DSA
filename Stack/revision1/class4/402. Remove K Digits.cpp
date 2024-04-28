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

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> st;
        int n = num.size();
        string ans = "";
        if (n <= k)
        {
            return "0";
        }
        int i = 0;
        while (i < n)
        {
            int ele = num[i] - '0';
            while (!st.empty() and st.top() > ele and k)
            {
                st.pop();
                k--;
            }
            st.push(ele);
            i++;
        }

        while (k--)
        {
            st.pop();
        }
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int c = 0;
        // cout<<ans;
        while (ans[c] == '0')
        {
            c++;
        }
        string final = ans.substr(c);
        return (final.size() == 0 ? "0" : final);
    }
};

int main()
{
    return 0;
}