#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &nums)
{
    for (int ele : nums)
        cout << ele << ' ';
    cout << endl;
}

int lengthOfLisTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lisDp(n, 0);
    vector<int> cntDp(n, 0);
    int maxLen = 0, maxCnt = 0;

    for (int i = 0; i < n; i++)
    {
        int prevIncSub = 0;
        int curCnt = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                if (lisDp[j] > prevIncSub)
                {
                    prevIncSub = lisDp[j];
                    curCnt = cntDp[j];
                }
                else if (lisDp[j] == prevIncSub)
                {
                    curCnt += cntDp[j];
                }
            }
        }
        lisDp[i] = prevIncSub + 1;
        cntDp[i] = curCnt;
        if (lisDp[i] > maxLen)
        {
            maxLen = lisDp[i];
            maxCnt = curCnt;
        }
        else if (lisDp[i] == maxLen)
        {
            maxCnt += curCnt;
        }
    }
    // display(lisDp);
    // display(cntDp);
    return maxCnt;
}

int findNumberOfLIS(vector<int> &nums)
{
    return lengthOfLisTabu(nums);
}

int main()
{
    // vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    vector<int> nums = {10, 8, 6, 4, 8};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}