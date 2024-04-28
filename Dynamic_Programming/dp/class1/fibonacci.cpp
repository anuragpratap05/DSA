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

void display(vector<int> &nums)
{
    for (int ele : nums)
        cout << ele << " , ";
    cout << endl;
}

int fiboRec(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    int ans = fiboRec(n - 1, dp) + fiboRec(n - 2, dp);
    return dp[n] = ans;
}

int fiboTabu(int N, vector<int> &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }

        dp[n] = dp[n - 1] + dp[n - 2];
    }
}

int main()
{
    int n = 7;
    vector<int> dp(n + 1, -1);
    // int fibo = fiboRec(n, dp);
    fiboTabu(n, dp);
    display(dp);
    // cout << "ans--> " << fibo;
    return 0;
}