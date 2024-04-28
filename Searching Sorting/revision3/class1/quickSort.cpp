#include <bits/stdc++.h>
using namespace std;

int segregate(vector<int> &nums, int s, int e)
{

    int prev = s - 1;
    for (int i = s; i <= e; i++)
    {
        if (nums[i] <= nums[e])
        {
            prev++;
            swap(nums[prev], nums[i]);
        }
    }
    return prev;
}

void quickSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pIdx = segregate(nums, s, e);
    quickSort(nums, s, pIdx - 1);
    quickSort(nums, pIdx + 1, e);
}
vector<int> sortArray(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> nums = {5, 2, 3, 1};
    // vector<int> nums = {5, 1, 1, 2, 0, 0};

    quickSort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
