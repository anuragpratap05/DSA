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
    int n = s.size();
    vector<int> freq;
    vector<bool> vis;
    freq.resize(26, 0);
    vis.resize(26, false);
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    // for(int e:freq)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        freq[ch - 'a']--;
        if (vis[ch - 'a'])
        {
            continue;
        }
        // cout << ch << " @ " << i << endl;
        while (!st.empty() and st.top() > ch and freq[st.top() - 'a'] > 0)
        {
            vis[st.top() - 'a'] = false;
            // cout <<"popped " <<st.top() << " by "<<ch<<endl;
            st.pop();
        }
        if (!vis[ch - 'a'])
        {
            vis[ch - 'a'] = true;

            // cout << endl;
            // cout << "pushed " << ch << endl;
            st.push(ch);
        }
    }
    string ans = "";
    // cout << endl;
    while (!st.empty())
    {
        // cout << st.top()<<" ";

        ans += st.top();
        st.pop();
    }
    // cout << endl;
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string str = "cbacdcbc";
    cout << removeDuplicateLetters(str);
    return 0;
}