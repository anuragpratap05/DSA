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
    int prev = -1;
    for (int i = idx; i < candidates.size(); i++)
    {
        int ele = candidates[i];
        int smallTarget = target - ele;
        if (smallTarget >= 0 and prev != ele)
        {
            prev = ele;
            sa.push_back(ele);
            cnt += combinationSumHelper(candidates, smallTarget, i + 1, ans, sa);
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
    cout << combinationSumHelper(candidates, target, 0, ans, sa) << endl;
    return ans;
}

int main()
{
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int tar = 8;
    vector<vector<int>> ans = combinationSum2(nums, tar);
    for (vector<int> &vec : ans)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}