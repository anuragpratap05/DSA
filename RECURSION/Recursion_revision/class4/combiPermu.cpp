#include <bits/stdc++.h>
using namespace std;

int permuSingleHelp(vector<int> &nums, int tar, vector<bool> &vis, int idx, string psf, int sum)
{
    if (idx == nums.size())
    {
        if (sum == tar)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    if (sum == tar)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            c += permuSingleHelp(nums, tar, vis, idx + 1, psf + to_string(nums[i]), sum + nums[i]);
            vis[i] = false;
        }
    }
    return c;
}

int permuSingle(vector<int> &nums, int tar)
{
    vector<bool> vis(nums.size(), false);
    return permuSingleHelp(nums, tar, vis, 0, "", 0);
}

int combiInfiHelp(vector<int> &nums, int tar, int idx, string psf, int sum)
{
    if (sum == tar)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int i = idx; i < nums.size(); i++)
    {
        if (sum + nums[i] <= tar)
        {
            c += combiInfiHelp(nums, tar, i, psf + to_string(nums[i]), sum + nums[i]);
        }
    }
    return c;
}

int combiInfi(vector<int> &nums, int tar)
{
    return combiInfiHelp(nums, tar, 0, "", 0);
}

int permuInfiHelp(vector<int> &nums, int tar, int sum, string psf)
{
    if (sum == tar)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] + sum <= tar)
            c += permuInfiHelp(nums, tar, sum + nums[i], psf + to_string(nums[i]));
    }
    return c;
}

int permuInfi(vector<int> &nums, int tar)
{
    return permuInfiHelp(nums, tar, 0, "");
}

int combiSingleHelp(vector<int> &nums, int tar, int idx, string psf, int sum)
{
    if (sum == tar)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int i = idx; i < nums.size(); i++)
    {
        c += combiSingleHelp(nums, tar, i + 1, psf + to_string(nums[i]), sum + nums[i]);
    }
    return c;
}

int combiSingle(vector<int> &nums, int tar)
{
    return combiSingleHelp(nums, tar, 0, "", 0);
}

//==================================================================================================

int combiSingleSubsequenceHelp(vector<int> &nums, int idx, string psf, int tar, int sum)
{
    if (idx == nums.size())
    {
        if (sum == tar)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int c = 0;
    c += combiSingleSubsequenceHelp(nums, idx + 1, psf + to_string(nums[idx]), tar, sum + nums[idx]);
    c += combiSingleSubsequenceHelp(nums, idx + 1, psf, tar, sum);
    return c;
}

int combiSingleSubsequence(vector<int> &nums, int tar)
{
    return combiSingleSubsequenceHelp(nums, 0, "", tar, 0);
}

int combiMultiSubsequenceHelp(vector<int> &nums, int tar, int idx, string psf, int sum)
{
    if (idx >= nums.size() or sum == tar)
    {
        if (sum == tar)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int c = 0;
    if (sum + nums[idx] <= tar)
        c += combiMultiSubsequenceHelp(nums, tar, idx, psf + to_string(nums[idx]), sum + nums[idx]);

    c += combiMultiSubsequenceHelp(nums, tar, idx + 1, psf, sum);

    return c;
}

int combiMultiSubsequence(vector<int> &nums, int tar)
{
    return combiMultiSubsequenceHelp(nums, tar, 0, "", 0);
}

int permuSingleSubsequenceHelp(vector<int> &nums, int tar, int idx, int sum, string psf, vector<bool> &vis)
{
    if (idx >= nums.size() or sum == tar)
    {
        if (sum == tar)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int c = 0;
    if (sum + nums[idx] <= tar and !vis[idx])
    {
        vis[idx] = true;
        c += permuSingleSubsequenceHelp(nums, tar, 0, sum + nums[idx], psf + to_string(nums[idx]), vis);
        vis[idx] = false;
    }

    c += permuSingleSubsequenceHelp(nums, tar, idx + 1, sum, psf, vis);

    return c;
}

int permuSingleSubsequence(vector<int> &nums, int tar)
{
    vector<bool> vis(nums.size(), false);
    return permuSingleSubsequenceHelp(nums, tar, 0, 0, "", vis);
}

int permuMultiSubsequenceHelp(vector<int> &nums, int tar, int idx, int sum, string psf)
{
    if (idx >= nums.size() or sum == tar)
    {
        if (sum == tar)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int c = 0;
    if (sum + nums[idx] <= tar)
    {
        c += permuMultiSubsequenceHelp(nums, tar, 0, sum + nums[idx], psf + to_string(nums[idx]));
    }
    c += permuMultiSubsequenceHelp(nums, tar, idx + 1, sum, psf);
    return c;
}

int permuMultiSubsequence(vector<int> &nums, int tar)
{
    // vector<bool> vis(nums.size(), false);
    return permuMultiSubsequenceHelp(nums, tar, 0, 0, "");
}
int main()
{
    vector<int> nums = {2, 3, 5, 7};
    int tar = 10;
    // cout << combiSingleSubsequence(nums, tar) << endl;
    // cout << permuSingle(nums, tar);
    // cout << combiInfi(nums, tar) << endl;
    // cout << permuInfi(nums, tar);
    // cout << combiSingle(nums, tar);
    // cout << combiMultiSubsequence(nums, tar) << endl;
    // cout << permuSingleSubsequence(nums, tar) << endl;
    cout << permuMultiSubsequence(nums, tar) << endl;
    return 0;
}