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

int numDecodingsHelp(string &s, int i, vector<long> &dp)
{

    if (i > s.size() or s[i] == '0')
        return 0;

    if (i == s.size())
    {
        return dp[i] = 1;
    }
    if (dp[i] != -1)
        return dp[i];

    long single = 0;
    if (s[i] == '*')
    {
        for (int num = 1; num <= 9; num++)
        {
            single += numDecodingsHelp(s, i + 1, dp);
        }
    }
    else
        single = numDecodingsHelp(s, i + 1, dp);

    long pairCall = 0;

    if (i + 1 < s.size())
    {
        if (s[i] != '*' and s[i + 1] == '*')
        {
            for (int num = 1; num <= 9; num++)
            {
                if (((s[i] - '0') * 10 + num) <= 26)
                {
                    pairCall += numDecodingsHelp(s, i + 2, dp);
                }
                else
                    break;
            }
        }
        else if (s[i] == '*' and s[i + 1] != '*')
        {
            for (int num = 1; num <= 2; num++)
            {
                if ((num * 10 + (s[i + 1] - '0')) <= 26)
                {
                    pairCall += numDecodingsHelp(s, i + 2, dp);
                }
                else
                    break;
            }
        }
        else if (s[i] == '*' and s[i + 1] == '*')
        {
            for (int num1 = 1; num1 <= 2; num1++)
            {
                for (int num2 = 1; num2 <= 9; num2++)
                {
                    if ((num1 * 10 + num2) <= 26)
                    {
                        pairCall += numDecodingsHelp(s, i + 2, dp);
                    }
                    else
                        break;
                }
            }
        }
        else
            pairCall = ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26 ? numDecodingsHelp(s, i + 2, dp) : 0;
    }

    return dp[i] = (single % 1000000007 + pairCall % 1000000007) % 1000000007;
}

int numDecodings(string s)
{
    vector<long> dp(s.size() + 1, -1);

    int ans = numDecodingsHelp(s, 0, dp);
    return ans;
}

int main()
{
    cout << "ans--> " << numDecodings("**");
    return 0;
}