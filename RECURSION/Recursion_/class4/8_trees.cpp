#include <bits/stdc++.h>
using namespace std;

int permutation_single_help(vector<int> &nums, int target, int idx, vector<bool> &vis, vector<vector<int>> &ans, vector<int> &sa)
{
    if (target == 0)
    {

        ans.push_back(sa);
        return 1;
    }
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i] and target - nums[i] >= 0)
        {
            vis[i] = true;
            sa.push_back(nums[i]);
            count += permutation_single_help(nums, target - nums[i], idx + 1, vis, ans, sa);
            vis[i] = false;
            sa.pop_back();
        }
    }
    return count;
}
vector<vector<int>> permutation_single(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    vector<bool> vis(candidates.size(), false);
    cout << permutation_single_help(candidates, target, 0, vis, ans, vec) << endl;
    return ans;
}

int permutation_multi_help(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &sa)
{
    if (target == 0)
    {

        ans.push_back(sa);
        return 1;
    }
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        if (target - nums[i] >= 0)
        {
            sa.push_back(nums[i]);
            count += permutation_multi_help(nums, target - nums[i], ans, sa);
            sa.pop_back();
        }
    }
    return count;
}
vector<vector<int>> permutation_multi(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    // vector<bool> vis(candidates.size(), false);
    cout << permutation_multi_help(candidates, target, ans, vec) << endl;
    return ans;
}

int combinationSingle_help(vector<int> &candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (target == 0)
    {

        ans.push_back(sa);
        // return 1;
    }
    // ans.push_back(sa);
    int count = 0;
    int p = 51;
    for (int i = idx; i < candidates.size(); i++)
    {
        if (candidates[i] != p and target - candidates[i] >= 0)
        {
            sa.push_back(candidates[i]);
            count += combinationSingle_help(candidates, target - candidates[i], i + 1, ans, sa);
            sa.pop_back();
        }
        p = candidates[i];
    }
    return count;
}
vector<vector<int>> combinationSingle(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    sort(candidates.begin(), candidates.end());
    cout << combinationSingle_help(candidates, target, 0, ans, vec) << endl;
    return ans;
}

int combinationmulti_help(vector<int> &candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (target == 0)
    {
        ans.push_back(sa);
        return 1;
    }
    int count = 0;
    for (int i = idx; i < candidates.size(); i++)
    {
        if (target - candidates[i] >= 0)
        {
            sa.push_back(candidates[i]);
            count += combinationmulti_help(candidates, target - candidates[i], i, ans, sa);
            sa.pop_back();
        }
    }
    return count;
}
vector<vector<int>> combination_multi(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    cout << combinationmulti_help(candidates, target, 0, ans, vec) << endl;
    return ans;
}

//================================================================================================================================

int single_coin_combi_sub_help(vector<int> &nums, int target, int idx, vector<int> &sa, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (target - nums[idx] >= 0)
    {
        sa.push_back(nums[idx]);
        count += single_coin_combi_sub_help(nums, target - nums[idx], idx + 1, sa, ans);
        sa.pop_back();
    }
    count += single_coin_combi_sub_help(nums, target, idx + 1, sa, ans);

    return count;
}
vector<vector<int>> single_coin_combi__sub(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    cout << single_coin_combi_sub_help(nums, target, 0, sa, ans) << endl;
    return ans;
}

int infi_coin_combi_sub_help(vector<int> &nums, int target, int idx, vector<int> &sa, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (target - nums[idx] >= 0)
    {
        sa.push_back(nums[idx]);
        count += infi_coin_combi_sub_help(nums, target - nums[idx], idx, sa, ans);
        sa.pop_back();
    }
    count += infi_coin_combi_sub_help(nums, target, idx + 1, sa, ans);

    return count;
}
vector<vector<int>> infi_coin_combi_sub(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    cout << infi_coin_combi_sub_help(nums, target, 0, sa, ans) << endl;
    return ans;
}

int infi_coinn_permu_sub_help(vector<int> &nums, int target, int idx, vector<int> &sa, vector<vector<int>> &ans)
{
    if (target == 0 or idx == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (target - nums[idx] >= 0)
    {
        sa.push_back(nums[idx]);
        count += infi_coinn_permu_sub_help(nums, target - nums[idx], 0, sa, ans);
        sa.pop_back();
    }
    count += infi_coinn_permu_sub_help(nums, target, idx + 1, sa, ans);
    return count;
}
vector<vector<int>> infi_coin_permu_sub(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    cout << infi_coinn_permu_sub_help(nums, target, 0, sa, ans) << endl;
    return ans;
}

int single_coinn_permu_sub_help(vector<int> &nums, int target, int idx, vector<int> &sa, vector<vector<int>> &ans, vector<bool> &vis)
{
    if (target == 0 or idx == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (target - nums[idx] >= 0 and !vis[idx])
    {
        sa.push_back(nums[idx]);
        vis[idx] = true;
        count += single_coinn_permu_sub_help(nums, target - nums[idx], 0, sa, ans, vis);
        sa.pop_back();
        vis[idx] = false;
    }
    count += single_coinn_permu_sub_help(nums, target, idx + 1, sa, ans, vis);
    return count;
}
vector<vector<int>> single_coin_permu_sub(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> sa;
    vector<bool> vis(nums.size(), false);
    cout << single_coinn_permu_sub_help(nums, target, 0, sa, ans, vis) << endl;
    return ans;
}

int main()
{
    vector<int> vec = {2, 3, 5, 7};

    vector<vector<int>> ans = combinationSingle(vec, 10);
    for (auto &vec : ans)
    {
        for (int ele : vec)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}