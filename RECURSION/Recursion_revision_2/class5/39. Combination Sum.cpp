#include <bits/stdc++.h>
using namespace std;

int combinationSumHelper(vector<int> &candidates, int tar, vector<vector<int>> &ans, vector<int> &sa, int idx)
{
    if (tar == 0)
    {
        ans.push_back(sa);

        return 1;
    }

    int cnt = 0;
    int prev = -1;

    for (int i = idx; i < candidates.size(); i++)
    {
        int ele = candidates[i];
        if (tar - ele >= 0 and ele != prev)
        {
            sa.push_back(ele);
            cnt += combinationSumHelper(candidates, tar - ele, ans, sa, i + 1);
            prev = ele;
            sa.pop_back();
        }
    }
    return cnt;
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, target, ans, sa, 0);
    return ans;
}

int main()
{
    return 0;
}