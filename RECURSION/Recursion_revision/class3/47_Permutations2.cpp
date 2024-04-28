#include <bits/stdc++.h>
using namespace std;
void permuteUniqueHelp(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa, vector<bool> &vis)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }
    int prevNo = -20;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (!vis[i] and prevNo != ele)
        {
            vis[i] = true;
            prevNo = ele;
            sa.push_back(ele);
            permuteUniqueHelp(nums, idx + 1, ans, sa, vis);
            vis[i] = false;
            sa.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> sa;
    vector<bool> vis(nums.size(), false);
    permuteUniqueHelp(nums, 0, ans, sa, vis);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(nums);
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