#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    int minVal = 1e8;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[s] < nums[mid])
        {
            minVal = min(minVal, nums[s]);
            s = mid + 1;
        }
        else
        {
            minVal = min(minVal, nums[mid]);
            e = mid - 1;
        }
    }
    return minVal;
}

int main()
{
    return 0;
}