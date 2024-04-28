#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &vec)
{
    for (int e : vec)
    {
        cout << e << ' ';
    }
}
void equalSetsHelper(vector<int> &nums, int sum1, int sum2, string set1, string set2, int idx)
{
    if (idx == nums.size())
    {
        if (sum1 == sum2)
        {
            cout << set1;
            cout << " = ";
            cout << set2 << endl;
        }
        return;
    }
    // set1 me aane ki call
    equalSetsHelper(nums, sum1 + nums[idx], sum2, set1 + to_string(nums[idx]) + " ", set2, idx + 1);

    // set2 me aane ki call
    equalSetsHelper(nums, sum1, sum2 + nums[idx], set1, set2 + to_string(nums[idx]) + " ", idx + 1);
}

void equalSets(vector<int> &nums)
{
    vector<int> set1;
    vector<int> set2;
    equalSetsHelper(nums, 0 + nums[0], 0, "" + to_string(nums[0]) + " ", "", 1);
}
int main()
{
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70};
    equalSets(nums);
    return 0;
}