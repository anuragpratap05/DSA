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

string removeKdigits(string num, int k)
{
    stack<char> st;
    for (char ch : num)
    {
        while (!st.empty() and st.top() < ch and k > 0)
        {
            st.pop();
            k--;
        }
        st.push(ch);
    }

    while (k--)
        st.pop();
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;
    while (i < ans.size())
    {
        if (ans[i] == '0')
            i++;
        else
            break;
    }

    string final = ans.substr(i, ans.size() - i);
    return final.size() == 0 ? "0" : final;
}

int main()
{
    return 0;
}