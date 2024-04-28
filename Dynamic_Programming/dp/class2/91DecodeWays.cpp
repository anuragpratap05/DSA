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

int numDecodingsHelp(string &s, int i, vector<int> &dp)
{

    if (i > s.size() or s[i] == '0')
        return 0;

    if (i == s.size())
    {
        return dp[i] = 1;
    }
    if (dp[i] != -1)
        return dp[i];

    int single = numDecodingsHelp(s, i + 1, dp);
    int pairCall = i + 1 < s.size() and ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26 ? numDecodingsHelp(s, i + 2, dp) : 0;

    return dp[i] = (single + pairCall);
}

int numDecodingsTabu(string &s, int i, vector<int> &dp)
{
    for (int i = s.size(); i >= 0; i--)
    {
        if (i == s.size() or s[i] == '0')
        {
            dp[i] = i == s.size() ? 1 : 0;
            continue;
        }

        int single = dp[i + 1];
        int pairCall = i + 1 < s.size() and ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26 ? dp[i + 2] : 0;

        dp[i] = (single + pairCall);
    }
    return dp[0];
}
int numDecodingsTabuOptimized(string &s, int i)
{
    int a = 1, b = 0, temp;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            temp = 0;
            b = a;
            a = temp;
            continue;
        }

        b = i + 1 < s.size() and ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26 ? b : 0;
        temp = a + b;
        b = a;
        a = temp;
    }
    return temp;
}

int numDecodings(string s)
{
    vector<int> dp(s.size() + 1, -1);

    int ans = numDecodingsTabuOptimized(s, 0);

    // return numDecodingsHelp(s, 0, dp);
    // int ans = numDecodingsTabu(s, 0, dp);
    // for (int ele : dp)
    //     cout << ele << " ";
    // cout << endl;
    return ans;
}

int main()
{
    string s = "11186";
    cout << numDecodings(s) << endl;
}