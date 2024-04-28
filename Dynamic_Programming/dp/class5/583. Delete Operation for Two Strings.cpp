#include <bits/stdc++.h>
using namespace std;

int minDistance(string &word1, string &word2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == word1.size() or i2 == word2.size())
    {
        return dp[i1][i2]= i1 == word1.size() ? word2.size() - i2 : word1.size() - i1;
    }
    if(dp[i1][i2]!=-1)
        return dp[i1][i2];
    if (word1[i1] == word2[i2])
        return dp[i1][i2] = minDistance(word1, word2, i1 + 1, i2 + 1, dp);
    else
        return dp[i1][i2] = min(minDistance(word1, word2, i1 + 1, i2, dp), minDistance(word1, word2, i1, i2 + 1, dp)) + 1;
}

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    return minDistance(word1, word2, 0, 0, dp);
}

int main()
{
    return 0;
}