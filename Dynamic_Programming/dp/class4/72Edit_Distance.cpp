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

int minDistanceHelp(string &word1, string &word2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == word1.size() or i2 == word2.size())
    {
        return dp[i1][i2] = i1 == word1.size() ? word2.size() - i2 : word1.size() - i1;
    }

    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    if (word1[i1] == word2[i2])
        return dp[i1][i2] = minDistanceHelp(word1, word2, i1 + 1, i2 + 1, dp);
    else
    {
        int insert = minDistanceHelp(word1, word2, i1, i2 + 1, dp);
        int del = minDistanceHelp(word1, word2, i1 + 1, i2, dp);
        int replace = minDistanceHelp(word1, word2, i1 + 1, i2 + 1, dp);
        return dp[i1][i2] = min(insert, min(del, replace)) + 1;
    }
}

int minDistanceTabu(string &word1, string &word2, int I1, int I2, vector<vector<int>> &dp)
{
    for (int i1 = word1.size(); i1 >= 0; i1--)
    {
        for (int i2 = word2.size(); i2 >= 0; i2--)
        {
            if (i1 == word1.size() or i2 == word2.size())
            {
                dp[i1][i2] = i1 == word1.size() ? word2.size() - i2 : word1.size() - i1;
                continue;
            }

            if (word1[i1] == word2[i2])
                dp[i1][i2] = dp[i1 + 1][i2 + 1]; // minDistanceHelp(word1, word2, i1 + 1, i2 + 1, dp);
            else
            {
                int insert = dp[i1][i2 + 1];      //  minDistanceHelp(word1, word2, i1, i2 + 1, dp);
                int del = dp[i1 + 1][i2];         //  minDistanceHelp(word1, word2, i1 + 1, i2, dp);
                int replace = dp[i1 + 1][i2 + 1]; //  minDistanceHelp(word1, word2, i1 + 1, i2 + 1, dp);
                dp[i1][i2] = min(insert, min(del, replace)) + 1;
            }
        }
    }
    return dp[I1][I2];
}

int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return minDistanceTabu(word1, word2, 0, 0, dp);
}

int main()
{
    string word1 = "intention", word2 = "execution";
    cout << "ans--> " << minDistance(word1, word2);

    return 0;
}