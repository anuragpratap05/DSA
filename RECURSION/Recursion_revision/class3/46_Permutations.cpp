#include <bits/stdc++.h>
using namespace std;



void permuteHelp(vector<int> &nums, vector<bool> &vis, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            sa.push_back(nums[i]);
            permuteHelp(nums, vis, idx + 1, ans, sa);
            vis[i] = false;
            sa.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> vis(n, false);
    vector<vector<int>> ans;
    vector<int> sa;
    permuteHelp(nums, vis, 0, ans, sa);
    return ans;
}

int main()
{
    vector<int> nums = {1};
    vector<vector<int>> ans = permute(nums);
    for (auto &vec : ans)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}