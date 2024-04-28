#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (k < 0)
    {
        k = k + n;
    }
    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + (k), nums.end());
    for(int e:nums)
    {
        cout << e << ' ';
    }
}

int main()
{
    vector<int> nums = {9, 7, 2, 8, 6, 3};
    int k = 4;
    rotate(nums, k);
    return 0;
}