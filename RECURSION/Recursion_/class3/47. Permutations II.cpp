#include<bits/stdc++.h>
using namespace std;
void help(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa, vector<bool> &vis)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        // display(sa);

        return;
    }
    int p=11;
    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i] or nums[i]==p)
        {
            continue;
        }
        vis[i] = true;
        sa.push_back(nums[i]);
        help(nums, idx + 1, ans, sa, vis);
        sa.pop_back();
        vis[i] = false;
        p=nums[i];
    }
    return;
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> sa;
    vector<bool> vis(nums.size(), false);
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    help(nums, 0, ans, sa, vis);
    return ans;
}

int main()
{
    return 0;
}