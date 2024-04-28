#include <bits/stdc++.h>
using namespace std;
int invCnt = 0;
void mergeTwoSortedArrays(vector<int> &nums, int s, int mid, int e, vector<int> &temp)
{
    int s1 = s, e1 = mid, s2 = mid + 1, e2 = e;
    // vector<int> temp((e - s) + 1);
    int k = 0;
    while (s1 <= e1 and s2 <= e2)
    {
        if (nums[s1] <=  nums[s2])
        {
            temp[k] = nums[s1];
            s1++;
            k++;
        }
        else
        {
            temp[k] = nums[s2];
            s2++;
            k++;
        }
    }
    while (s1 <= e1)
    {
        temp[k] = nums[s1];
        s1++;
        k++;
    }
    while (s2 <= e2)
    {
        temp[k] = nums[s2];
        s2++;
        k++;
    }
    k = 0;
    for (int i = s; i <= e; i++)
    {
        nums[i] = temp[k];
        k++;
    }
}

void sortArray_(vector<int> &nums, int s, int e, vector<int> &temp)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    sortArray_(nums, s, mid, temp);
    sortArray_(nums, mid + 1, e, temp);
    mergeTwoSortedArrays(nums, s, mid, e, temp);
}

int main()
{
    vector<int> nums = {8, 5, 1, 18, 12, 13, 16, 14, 19, 5};
    vector<int> temp(nums.size(), 0);
    sortArray_(nums, 0, nums.size() - 1, temp);
    for (int e : nums)
    {
        cout << e << ' ';
    }

    return 0;
}