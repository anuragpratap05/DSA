#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int s, int e, int tar)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == tar)
        {
            return mid;
        }
        if (tar < nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        int ele = numbers[i];
        int secondEleIdx = binarySearch(numbers, i + 1, numbers.size() - 1, target - ele);
        if (secondEleIdx != -1)
        {

            secondEleIdx += 1;
            return {i + 1, secondEleIdx};
        }
    }
    return {};
}

int main()
{
    return 0;
}