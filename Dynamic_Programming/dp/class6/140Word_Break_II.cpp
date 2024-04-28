#include <bits/stdc++.h>
using namespace std;

vector<bool> wordBreakTabu(string s, vector<string> &wordDict)
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
    return dp;
}

void backEngine(vector<bool> &dp, string psf, vector<string> &ans, int maxLen, int idx, string &s, unordered_set<string> &st)
{
    if (idx == s.size())
    {
        ans.push_back(psf);
        return;
    }

    for (int len = 1; len <= maxLen && idx + len <= s.size(); len++)
    {
        if (dp[idx + len])
        {
            string sub = s.substr(idx, len);
            if (st.find(sub) != st.end())
            {
                backEngine(dp, psf == "" ? sub : psf + " " + sub, ans, maxLen, idx + len, s, st);
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp = wordBreakTabu(s, wordDict);

    unordered_set<string> st;
    dp[0] = true;
    int maxLen = 0;

    for (string &str : wordDict)
    {
        st.insert(str);
        int wordLen = str.size();
        maxLen = max(maxLen, wordLen);
    }
    string psf = "";
    vector<string> ans;
    backEngine(dp, psf, ans, maxLen, 0, s, st);
    return ans;
}

int main()
{
    string s = "mangoandsamsung";
    // string s = "catsanddog";
    vector<string> wordDict = {"man",
                               "go",
                               "mango",
                               "and",
                               "sam",
                               "sung",
                               "samsung"};

    // vector<string>
    //     wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = wordBreak(s, wordDict);
    for (string &str : ans)
        cout << str << endl;

    return 0;
}