#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int cumSum = 0, ans = 0;
    vector<int> freq(k, 0);
    freq[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        cumSum += ele;
        int rem = cumSum % k;
        if (rem < 0)
        {
            rem += k;
        }
        ans += freq[rem];
        freq[rem]++;
    }
    return ans;
}

int main()
{
    // int rem = -4 % 5;
    // cout << rem;
    vector<int> nums = {4,
                        5,
                        0,
                        -2,
                        -3,
                        1};
    int k = 5;

    cout << subarraysDivByK(nums, k);
    return 0;
}