#include <bits/stdc++.h>
using namespace std;

int combiSingleCoinHelper(vector<int> &nums, int tar, string psf, int idx)
{
    if (tar == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;
    for (int i = idx; i < nums.size(); i++)
    {
        if (tar - nums[i] >= 0)
            cnt += combiSingleCoinHelper(nums, tar - nums[i], psf + to_string(nums[i]), i + 1);
    }
    return cnt;
}

int combiSingleCoinSub(vector<int> &nums, int tar, string psf, int idx)
{
    if (tar == 0 or idx == nums.size())
    {
        if (tar == 0)
        {
            cout << psf << endl;
            return 1;
        }

        return 0;
    }

    int cnt = 0;

    if (tar - nums[idx] >= 0)
        cnt += combiSingleCoinSub(nums, tar - nums[idx], psf + to_string(nums[idx]), idx + 1);
    cnt += combiSingleCoinSub(nums, tar, psf, idx + 1);
    return cnt;
}

int combiSingleCoin(vector<int> &nums, int tar)
{
    // return combiSingleCoinHelper(nums, tar, "", 0);
    return combiSingleCoinSub(nums, tar, "", 0);
}

//++++++++++++++++++++++++++++++++=============+++++++++++++================+++++++++++++++++++++

int permuSingleCoinHelper(vector<int> &nums, int tar, string psf)
{
    if (tar == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele != -1)
        {
            int reducedTar = tar - ele;
            if (reducedTar >= 0)
            {
                nums[i] = -1;
                cnt += permuSingleCoinHelper(nums, reducedTar, psf + to_string(ele));
                nums[i] = ele;
            }
        }
    }
    return cnt;
}

int permuSingleCoinSub(vector<int> &nums, int tar, string psf, int idx)
{
    if (tar == 0 or idx == nums.size())
    {
        if (tar == 0)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    int ele = nums[idx];
    if (ele != -11 and tar - ele >= 0)
    {
        nums[idx] = -11;
        cnt += permuSingleCoinSub(nums, tar - ele, psf + to_string(ele), 0);
        nums[idx] = ele;
    }

    cnt += permuSingleCoinSub(nums, tar, psf, idx + 1);
    return cnt;
}

int permuSingleCoin(vector<int> &nums, int tar)
{
    // return permuSingleCoinHelper(nums, tar, "");
    return permuSingleCoinSub(nums, tar, "", 0);
}

//+++++++++++++++==================+++++++++++++++++===================+++++++++++++++++++++=====

int combiMultiCoinHelper(vector<int> &nums, int tar, int idx, string psf)
{
    if (tar == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;

    for (int i = idx; i < nums.size(); i++)
    {
        int ele = nums[i];
        int reducedTar = tar - ele;
        if (reducedTar >= 0)
        {
            cnt += combiMultiCoinHelper(nums, reducedTar, i, psf + to_string(ele));
        }
    }
    return cnt;
}

int combiMultiCoinSub(vector<int> &nums, int tar, int idx, string psf)
{
    if (tar == 0 or idx == nums.size())
    {
        if (tar == 0)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    if (tar - nums[idx] >= 0)
    {
        cnt += combiMultiCoinSub(nums, tar - nums[idx], idx, psf + to_string(nums[idx]));
    }
    cnt += combiMultiCoinSub(nums, tar, idx + 1, psf);
    return cnt;
}

int combiMultiCoin(vector<int> &nums, int tar)
{
    // return combiMultiCoinHelper(nums, tar, 0, "");
    return combiMultiCoinSub(nums, tar, 0, "");
}

//++++++++++++=================+++++++++++++++++================++++++++++++++++=================

int permuMultiCoinHelper(vector<int> &nums, int tar, string psf)
{
    if (tar == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        int reducedTar = tar - ele;
        if (reducedTar >= 0)
        {
            cnt += permuMultiCoinHelper(nums, reducedTar, psf + to_string(ele));
        }
    }
    return cnt;
}

int permuMultiCoinSub(vector<int> &nums, int tar, string psf, int idx)
{
    if (tar == 0 or nums.size() == idx)
    {
        if (tar == 0)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int cnt = 0;
    if (tar - nums[idx] >= 0)
    {
        cnt += permuMultiCoinSub(nums, tar - nums[idx], psf + to_string(nums[idx]), 0);
    }
    cnt += permuMultiCoinSub(nums, tar, psf, idx + 1);
    return cnt;
}

int permuMultiCoin(vector<int> &nums, int tar)
{
    // return permuMultiCoinHelper(nums, tar, "");
    return permuMultiCoinSub(nums, tar, "", 0);
}                                                                                       

int main()
{
    vector<int> nums = {2, 3, 5, 7};
    int tar = 10;
    // cout << combiSingleCoin(nums, tar);
    // cout << permuSingleCoin(nums, tar);
    // cout << combiMultiCoin(nums, tar);
    cout << permuMultiCoin(nums, tar);
    return 0;
}