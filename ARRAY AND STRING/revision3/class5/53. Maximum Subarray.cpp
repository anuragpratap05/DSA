#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    bool positivePresent = false;
    int cumSum = 0;
    int positiveMax = -1e9;
    int negativeMax = -1e9;

    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele > negativeMax)
        {
            negativeMax = ele;
        }
        if (ele > 0)
        {
            positivePresent = true;
        }
        cumSum += ele;
        if (cumSum <= 0)
        {
            cumSum = 0;
        }
        positiveMax = max(positiveMax, cumSum);
    }
    if (positivePresent)
    {
        return positiveMax;
    }
    return negativeMax;
}

int main()
{
    return 0;
}