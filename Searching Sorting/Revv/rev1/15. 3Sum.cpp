#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &numbers, int target, int fEle, int s, vector<vector<int>> &ans)
{
    int e = numbers.size() - 1;

    while (s <= e)
    {
        int curSum = numbers[s] + numbers[e];
        if (curSum == target)
        {
            ans.push_back({fEle, numbers[s], numbers[e]});
            s++;
            e--;
            while (s<e and numbers[s] == numbers[s - 1])
                s++;
            while (s<e and numbers[e] == numbers[e + 1])
                e--;
        }
        else if (curSum > target)
            e--;
        else
            s++;
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2;)
    {
        int ele = nums[i];
        twoSum(nums, 0 - ele, ele, i + 1, ans);
        i++;
        while (i < n - 2 and nums[i] == ele)
            i++;
    }
    return ans;
}

int main()
{
    return 0;
}