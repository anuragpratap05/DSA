#include <bits/stdc++.h>
using namespace std;

void permuteHelp(vector<int> &nums, vector<vector<int>> &ans, vector<int> &sa)
{
    if (sa.size() == nums.size())
    {
        ans.push_back(sa);
        return;
    }

    int prev = -11;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (prev != ele and ele != -11)
        {
            sa.push_back(ele);
            nums[i] = -11;
            permuteHelp(nums, ans, sa);
            sa.pop_back();
            nums[i] = ele;
            prev = ele;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> sa;
    permuteHelp(nums, ans, sa);
    return ans;
}

int main()
{
    return 0;
}