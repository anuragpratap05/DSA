#include <bits/stdc++.h>
using namespace std;

int combinationSumHelper(vector<int> &candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (target == 0)
    {
        ans.push_back(sa);
        return 1;
    }
    int cnt = 0;
    for (int i = idx; i < candidates.size(); i++)
    {
        int ele = candidates[i];
        int smallTarget = target - ele;
        if (smallTarget >= 0)
        {
            sa.push_back(ele);
            cnt += combinationSumHelper(candidates, smallTarget, i, ans, sa);
            sa.pop_back();
        }
    }
    return cnt;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    cout << combinationSumHelper(candidates, target, 0, ans, sa);
    return ans;
}

int main()
{
    return 0;
}