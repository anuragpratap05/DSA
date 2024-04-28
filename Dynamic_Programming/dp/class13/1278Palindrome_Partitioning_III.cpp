#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &dp)
{
    int n = dp.size();
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int palindromePartitionMemo(string &s, int k, int si, vector<vector<int>> &dp, vector<vector<int>> &mainDp)
{
    if (k == 1)
        return dp[si][s.size() - 1];
    if (mainDp[si][k] != -1)
        return mainDp[si][k];
    int minVal = 1e8;
    for (int cut = si; cut <= s.size() - k; cut++)
    {
        int left = dp[si][cut];
        int right = palindromePartitionMemo(s, k - 1, cut + 1, dp, mainDp);

        minVal = min(minVal, left + right);
    }
    return mainDp[si][k] = minVal;
}

int palindromePartition(string s, int k)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> mainDp(n, vector<int>(k + 1, -1));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 0;
            }
            else if (gap == 1)
            {
                dp[i][j] = s[i] == s[j] ? 0 : 1;
            }
            else
            {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : dp[i + 1][j - 1] + 1;
            }
        }
    }
    return palindromePartitionMemo(s, k, 0, dp, mainDp);
}

int main()
{
    string s = "aabbc";
    int k = 3;
    int minChanges = palindromePartition(s, k);

    cout << "Min Changes = " << minChanges << endl;

    return 0;
}