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

void display(vector<vector<int>> &dp)
{
    for (vector<int> &vec : dp)
    {
        for (int ele : vec)
            cout << ele << ' ';
        cout << endl;
    }
}

string longestPalindrome(string s)
{
    int maxLen = 0, maxLenSi = 0, maxLenEi = 0, totPalindromicSubstring = 0;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
                totPalindromicSubstring++;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    maxLenSi = i;
                    maxLenEi = j;
                }
            }
            else if (s[i] == s[j])
            {
                if (gap == 1)
                {
                    dp[i][j] = 2;
                    totPalindromicSubstring++;
                    if (dp[i][j] > maxLen)
                    {
                        maxLen = dp[i][j];
                        maxLenSi = i;
                        maxLenEi = j;
                    }
                }
                else
                {
                    if (dp[i + 1][j - 1] != 0)
                    {
                        totPalindromicSubstring++;
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                        if (dp[i][j] > maxLen)
                        {
                            maxLen = dp[i][j];
                            maxLenSi = i;
                            maxLenEi = j;
                        }
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    // display(dp);
    // cout << "maxLen--> " << maxLen << endl;
    // cout << "totPalindromicSubstring--> " << totPalindromicSubstring << endl;
    string longestSubstr = s.substr(maxLenSi, (maxLenEi - maxLenSi) + 1);
    // cout << "longestSubstr--> " << longestSubstr;
    return longestSubstr;
}

int main()
{
    string s = "gegpeepf";
    longestPalindrome(s);
    return 0;
}