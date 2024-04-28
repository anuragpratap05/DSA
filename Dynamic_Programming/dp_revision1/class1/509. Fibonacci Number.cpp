#include <bits/stdc++.h>
using namespace std;

int fibDp(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibDp(n - 1, dp) + fibDp(n - 2, dp);
}

int fibDpTabu(int N, vector<int> &dp)
{

    for (int n = 0; n <= N; n++)
    {
        if (n == 0 or n == 1)
        {
            dp[n] = n;
            continue;
        }

        dp[n] = dp[n - 1] + dp[n - 2];
    }
    return dp[N];
}

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return fibDpTabu(n, dp);
    return fibDp(n, dp);
}

int main()
{
    return 0;
}