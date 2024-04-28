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

bool wordBreakHelp(string &s, unordered_set<string> &st, int idx, vector<int> &dp)
{
    if (idx == s.size())
        return dp[idx] = true;
    if (dp[idx] != -1)
        return dp[idx];

    string str = "";

    bool found = false;
    int i = idx;
    for (; i < s.size(); i++)
    {
        str += s[i];
        if (st.find(str) != st.end())
        {
            found = wordBreakHelp(s, st, i + 1, dp);
            if (found)
                return dp[i] = true;
        }
    }

    return dp[i] = found;
}

bool wordBreakTabu(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    int len = 0;
    for (string &str : wordDict)
    {
        st.insert(str);
        int wordLen = str.size();
        len = max(len, wordLen);
    }

    for (int i = 0; i <= s.size(); i++)
    {
        if (!dp[i])
            continue;

        for (int l = 1; l <= len and l + i <= s.size(); l++)
        {
            string sub = s.substr(i, l);
            // cout<<"i--> "<<i<< "sub--> "<<sub<<endl;
            if (st.find(sub) != st.end())
            {
                dp[i + l] = true;
                // cout<<"i+l--> "<<i+l<<endl;
            }
        }
    }
    return dp[s.size()];
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    vector<int> dp(s.size() + 1, -1);

    for (string &str : wordDict)
        st.insert(str);
    return wordBreakHelp(s, st, 0, dp);
}

int main()
{
    string s = "mangoandsamsung";
    string x = s.substr(0, 3);
    cout << "x--> " << x << endl;
    return 0;
}