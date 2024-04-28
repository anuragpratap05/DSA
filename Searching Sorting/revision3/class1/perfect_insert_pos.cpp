#include <bits/stdc++.h>
using namespace std;

int perfectInsertPos(vector<long long> &nums, long long tar)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] <= tar)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}

int main()
{
    return 0;
}