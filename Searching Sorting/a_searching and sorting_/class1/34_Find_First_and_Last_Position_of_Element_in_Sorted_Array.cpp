#include <bits/stdc++.h>
using namespace std;
int binary_searchsi(vector<int> &arr, int tar)
{
    int n = arr.size();
    int ei = n - 1, si = 0;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (tar == arr[mid])
        {
            if (arr[mid - 1] != tar)
                return mid;

            ei = mid - 1;
            continue;
        }
        if (arr[mid] < tar)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return -1;
}
int binary_searchei(vector<int> &arr, int tar)
{
    int n = arr.size();
    int ei = n - 1, si = 0;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (tar == arr[mid])
        {
            if (arr[mid + 1] != tar)
                return mid;

            si = mid + 1;
            continue;
        }
        if (arr[mid] < tar)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int si = -2, ei = -2;
    int n = nums.size();
    if (n == 0)
    {
        return {-1, -1};
    }
    if (nums[0] == target)
    {
        si = 0;
    }
    if (nums[n - 1] == target)
    {
        ei = n - 1;
    }

    if (si == -2)
    {
        si = binary_searchsi(nums, target);
        cout << "si=" << si << endl;
    }
    if (ei == -2)
    {
        ei = binary_searchei(nums, target);
        cout << "ei=" << ei << endl;
    }
    return {si, ei};
}

int main()
{
    int atr = 3;
    vector<int> nums = {1, 2, 3, 3, 3, 3, 4, 5, 9};
    searchRange(nums, atr);

    return 0;
}