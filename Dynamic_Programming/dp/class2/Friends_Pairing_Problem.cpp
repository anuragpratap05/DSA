#include <bits/stdc++.h>
using namespace std;

long countFriendsPairingsHelp(int n, vector<long> &dp)
{
    int mod = (int)1e9 + 7;
    if (n == 0)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    long single = countFriendsPairingsHelp(n - 1, dp);
    long couple = n > 1 ? (n - 1) * countFriendsPairingsHelp(n - 2, dp) : 0;
    return dp[n] = (single + couple % mod) % mod;
}

int countFriendsPairings(int n)
{
    vector<long> dp(n + 1, -1);
    return n == 0 ? 0 : countFriendsPairingsHelp(n, dp);
}

int main()
{
    cout << "ans--> " << countFriendsPairings(4) << endl;
    return 0;
}