#include <bits/stdc++.h>
using namespace std;

void permuteUnique(vector<int> &nums, int idx, vector<int> &sa, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }
    int prev = -11;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele != -11 and ele != prev)
        {
            sa.push_back(ele);
            nums[i] = -11;
            permuteUnique(nums, idx + 1, sa, ans);
            sa.pop_back();
            prev = ele;
            nums[i] = ele;
        }
    }
}


// cant manage prev thing using subseq method
void permuteUniqueSubseq(vector<int> &nums, int idx, vector<int> &sa, vector<vector<int>> &ans, int taken)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }

    int prev = -11;
    int ele = nums[idx];

    if (ele != -11 and prev != ele)
    {
        nums[idx] = -11;
        sa.push_back(ele);
        permuteUniqueSubseq(nums, 0, sa, ans, taken + 1);
        prev = ele;
        nums[idx] = ele;
        sa.pop_back();
    }
    permuteUniqueSubseq(nums, idx + 1, sa, ans, taken);
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> sa;
    vector<vector<int>> ans;
    permuteUnique(nums, 0, sa, ans, 0);
    return ans;
}

int main()
{
    return 0;
}