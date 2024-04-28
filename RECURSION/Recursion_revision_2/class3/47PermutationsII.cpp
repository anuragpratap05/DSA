#include <bits/stdc++.h>
using namespace std;
void permuteHelp(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }
    vector<bool> unique(20, false);
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele != -11)
        {
            int x = ele + 21;
            int rem = x % 21;
            if (!unique[rem])
            {
                sa.push_back(ele);
                nums[i] = -11;
                unique[rem] = true;
                permuteHelp(nums, idx + 1, ans, sa);
                sa.pop_back();
                nums[i] = ele;
            }
        }
    }
}

void permuteHelpSpaceOptimized(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }
    int p = -11;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele != -11 and ele != p)
        {
            sa.push_back(ele);
            nums[i] = -11;
            permuteHelpSpaceOptimized(nums, idx + 1, ans, sa);
            p = ele;
            nums[i] = ele;
            sa.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> sa;
    vector<vector<int>> ans;
    // permuteHelp(nums, 0, ans, sa);
    permuteHelpSpaceOptimized(nums, 0, ans, sa);
    // permuteHelpSubseq(nums, 0, ans, sa, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<vector<int>> ans = permuteUnique(nums);
    for (vector<int> &vec : ans)
    {
        for (int e : vec)
        {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}