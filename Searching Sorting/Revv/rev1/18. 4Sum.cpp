#include <bits/stdc++.h>
using namespace std;
void twoSum(vector<int> &numbers, long long target, int s, int fEle, int sEle, vector<vector<int>> &ans)
{
    int e = numbers.size() - 1;

    while (s < e)
    {
        int curSum = numbers[s] + numbers[e];
        if (curSum == target)
        {
            ans.push_back({fEle, sEle, numbers[s], numbers[e]});
            s++;
            e--;
            while (s < e and numbers[s] == numbers[s - 1])
                s++;
            while (s < e and numbers[e] == numbers[e + 1])
                e--;
        }
        else if (curSum > target)
            e--;
        else
            s++;
    }
}

vector<vector<int>> threeSum(vector<int> &nums, long long tar, int si, int fEle, vector<vector<int>> &ans)
{
    int n = nums.size();
    for (int i = si; i < n - 2;)
    {
        int ele = nums[i];
        twoSum(nums, tar - ele, i + 1, fEle, ele, ans);
        i++;
        while (i < n - 2 and nums[i] == ele)
            i++;
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 3;)
    {
        int ele = nums[i];
        threeSum(nums, target - ele, i + 1, ele, ans);
        i++;
        while (i < n - 3 and nums[i] == ele)
            i++;
    }
    return ans;
}

int main()
{
    return 0;
}