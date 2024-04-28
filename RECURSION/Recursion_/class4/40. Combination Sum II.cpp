#include<bits/stdc++.h>
using namespace std;

int combinationSum_help(vector<int> &candidates, int target, int sum, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (sum >= target or idx == candidates.size())
    {
        if (sum == target)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    int p = 51;
    for (int i = idx; i < candidates.size(); i++)
    {
        if (candidates[i] != p)
        {
            sa.push_back(candidates[i]);
            count += combinationSum_help(candidates, target, sum + candidates[i], i + 1, ans, sa);
            sa.pop_back();
        }
        p = candidates[i];
    }
    return count;
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    combinationSum_help(candidates, target, 0, 0, ans, vec);
    return ans;
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    return combinationSum(candidates, target);
}

int main()
{
    return 0;
}