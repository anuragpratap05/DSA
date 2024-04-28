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

string removeDuplicateLetters(string s)
{
    vector<int> freq(25, 0);
    vector<bool> vis(25, false);

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    stack<char> st;

    for (char ch : s)
    {
        freq[ch - 'a']--;
        if (vis[ch - 'a'])
            continue;
        while (!st.empty() and st.top() >= ch and freq[st.top() - 'a'] > 0)
        {
            vis[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(ch);
        vis[ch - 'a'] = true;
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}