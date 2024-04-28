#include <bits/stdc++.h>
using namespace std;

int countFriendsPairingsHelp(int n, int taken, string psf, vector<bool> &vis)
{
    if (taken >= n)
    {
        // cout << psf << endl;
        return 1;
    }
    int i = 1;
    for (; i <= n; i++)
    {
        if (!vis[i])
            break;
    }
    vis[i] = true;
    int count = 0;
    count += countFriendsPairingsHelp(n, taken + 1, psf + " " + to_string(i) + " ", vis);

    for (int next = i + 1; next <= n; next++)
    {
        if (!vis[next])
        {
            vis[next] = true;
            count += countFriendsPairingsHelp(n, taken + 2, psf + " " + to_string(i) + to_string(next) + " ", vis);
            vis[next] = false;
        }
    }
    vis[i] = false;
    return count;
}

long friendsPairingDp(int n, vector<long> &dp)
{
    if (n == 0)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    int mod = (int)1e9 + 7;

    long single = friendsPairingDp(n - 1, dp);
    long couple = n > 1 ? (n - 1) * friendsPairingDp(n - 2, dp) : 0;

    return dp[n] = (single + couple % mod) % mod;
}

int countFriendsPairings(int n)
{
    vector<long> dp(n + 1, -1);
    return n == 0 ? 0 : friendsPairingDp(n, dp);
    // vector<bool> vis(n + 1, false);
    // return countFriendsPairingsHelp(n, 0, "", vis);
}

int main()
{
    int combinations = countFriendsPairings(5);
    cout << "Total combinations are: " << combinations << endl;
    return 0;
}