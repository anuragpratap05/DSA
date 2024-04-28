#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<string>> &ans)
{
    for (vector<string> &vec : ans)
    {
        for (string &str : vec)
            cout << str << " ";
        cout << endl;
    }
}

int partitionHelper(string &s, vector<vector<string>> &ans, vector<string> &sa, int si, vector<vector<bool>> &dp)
{
    if (si == s.size())
    {
        ans.push_back(sa);
        return 1;
    }
    int cnt = 0;
    for (int cut = si; cut < s.size(); cut++)
    {
        if (dp[si][cut])
        {
            sa.push_back(s.substr(si, (cut - si) + 1));
            cnt += partitionHelper(s, ans, sa, cut + 1, dp);
            sa.pop_back();
        }
    }
    return cnt;
}

vector<vector<string>> partition(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1)
            {
                dp[i][j] = s[i] == s[j];
            }
            else
            {
                dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1];
            }
        }
    }

    vector<vector<string>> ans;
    vector<string> sa;
    int vecs = partitionHelper(s, ans, sa, 0, dp);
    return ans;
}

int main()
{
    string s = "xcdckfakaft";
    vector<vector<string>> ans = partition(s);
    display(ans);
    return 0;
}