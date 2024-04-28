#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[s] == target or nums[mid] == target)
        {
            return true;
        }
        if (nums[s] < nums[mid])
        {
            if (target >= nums[s] and target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (nums[mid] < nums[e])
        {
            if (target > nums[mid] and target <= nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        else
        {
            s++;
        }
    }
    return false;
}

int main()
{
    return 0;
}