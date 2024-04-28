#include <bits/stdc++.h>
using namespace std;

void displayDp(vector<vector<int>> &dp)
{
    for (vector<int> &vec : dp)
    {
        for (int ele : vec)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
}

int isSubsetSumHelp(vector<int> &arr, int sum, int idx, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return dp[sum][idx] = 1;
    }
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    int found = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        int coin = arr[i];
        if (sum - coin >= 0)
        {
            found = isSubsetSumHelp(arr, sum - coin, i + 1, dp);
            if (found == 1)
                return dp[sum][idx] = 1;
        }
    }
    return dp[sum][idx] = found;
}

int isSubsetSumSubseqMqthod(vector<int> &arr, int sum, int idx, vector<vector<int>> &dp)
{
    if (sum == 0 or idx == arr.size())
        return dp[idx][sum] = sum == 0 ? 1 : 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    int include = 0, exclude = 0;
    if (sum - arr[idx] >= 0)
        include = isSubsetSumSubseqMqthod(arr, sum - arr[idx], idx + 1, dp);
    exclude = isSubsetSumSubseqMqthod(arr, sum, idx + 1, dp);
    return dp[idx][sum] = (include || exclude);
}

int AllPaths_backEngine(vector<vector<int>> &dp, vector<int> &arr, int idx, int tar, string psf)
{

    if (tar == 0)
    {
        cout << psf << endl;
        return 1;
    }

    int cnt = 0;
    if (tar - arr[idx] >= 0 and dp[idx + 1][tar - arr[idx]] == 1)
        cnt += AllPaths_backEngine(dp, arr, idx + 1, tar - arr[idx], psf + to_string(arr[idx]) + " ");
    if (dp[idx + 1][tar] == 1)
        cnt += AllPaths_backEngine(dp, arr, idx + 1, tar, psf);
    return cnt;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int ans = isSubsetSumSubseqMqthod(arr, sum, 0, dp);
    displayDp(dp);
    int noOfPaths = AllPaths_backEngine(dp, arr, 0, sum, "");
    cout << "noOfPaths--> " << noOfPaths << endl;
    // int ans = isSubsetSumHelp(arr, sum, 0, dp);
    if (ans == 1)
        return true;
    else
        return false;
}

int main()
{
    int tar = 10;
    // int tar = 9;
    vector<int> coins = {2, 3, 5, 7};
    // vector<int> coins = {4, 34, 12, 5, 2};
    bool found = isSubsetSum(coins, tar);
    if (found)
    {
        cout << "POSSIBLE";
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}