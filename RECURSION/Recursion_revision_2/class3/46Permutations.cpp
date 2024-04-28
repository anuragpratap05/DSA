#include <bits/stdc++.h>
using namespace std;


// Loop Method it comes first in mind
void permuteHelp(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele != -11)
        {
            sa.push_back(ele);
            nums[i] = -11;
            permuteHelp(nums, idx + 1, ans, sa);
            sa.pop_back();
            nums[i] = ele;
        }
    }
}

// Subsequence Method:-
void permuteHelpSubseq(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa, int selectCount)
{
    if (selectCount == nums.size() or idx == nums.size())
    {
        if (selectCount == nums.size())
            ans.push_back(sa);
        return;
    }

    int ele = nums[idx];
    if (ele != -11)
    {
        sa.push_back(ele);
        nums[idx] = -11;
        permuteHelpSubseq(nums, 0, ans, sa, selectCount + 1);
        sa.pop_back();
        nums[idx] = ele;
    }

    permuteHelpSubseq(nums, idx + 1, ans, sa, selectCount);
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> sa;
    vector<vector<int>> ans;
    // permuteHelp(nums, 0, ans, sa);
    permuteHelpSubseq(nums, 0, ans, sa, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
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