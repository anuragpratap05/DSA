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

int numDistinctHelp(string s, string t, int i1, int i2, vector<vector<int>> &dp)
{
    if (i2 == t.size() or t.size() - i2 > s.size() - i1)
        return dp[i1][i2] = i2 == t.size() ? 1 : 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (s[i1] == t[i2])
    {
        int removedBothChars = numDistinctHelp(s, t, i1 + 1, i2 + 1, dp);
        int tAsItIs = numDistinctHelp(s, t, i1 + 1, i2, dp);
        return dp[i1][i2] = removedBothChars + tAsItIs;
    }
    else
        return dp[i1][i2] = numDistinctHelp(s, t, i1 + 1, i2, dp);
}

int numDistinctTabu(string s, string t, int I1, int I2, vector<vector<int>> &dp)
{
    for (int i1 = s.size(); i1 >= 0; i1--)
    {
        for (int i2 = t.size(); i2 >= 0; i2--)
        {
            if (i2 == t.size() or t.size() - i2 > s.size() - i1)
            {
                dp[i1][i2] = i2 == t.size() ? 1 : 0;
                continue;
            }

            if (s[i1] == t[i2])
            {
                int removedBothChars = dp[i1 + 1][i2 + 1]; // numDistinctHelp(s, t, i1 + 1, i2 + 1, dp);
                int tAsItIs = dp[i1 + 1][i2];              // numDistinctHelp(s, t, i1 + 1, i2, dp);
                dp[i1][i2] = removedBothChars + tAsItIs;
            }
            else
                dp[i1][i2] = dp[i1 + 1][i2]; // numDistinctHelp(s, t, i1 + 1, i2, dp);
        }
    }
    return dp[I1][I2];
}

int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return numDistinctTabu(s, t, 0, 0, dp);
}

int main()
{
    string s = "geeksforgeeks";
    string t = "gks";
    cout << "ans--> " << numDistinct(s, t) << endl;
    return 0;
}