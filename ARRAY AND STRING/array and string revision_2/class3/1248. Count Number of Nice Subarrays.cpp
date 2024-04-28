#include <bits/stdc++.h>
using namespace std;

int atmostK_odd(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int n = nums.size();
    int i = 0;
    int p = 0;
    int len = 0;
    int cnt = 0;
    while (i < n)
    {
        int ele = nums[i];
        if (ele % 2 != 0)
        {
            cnt++;
        }

        while (cnt > k)
        {
            int nele = nums[p];
            if (nele % 2 != 0)
            {
                cnt--;
            }
            p++;
        }
        i++;
        len += (i - p);
    }
    return len;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    int a = atmostK_odd(nums, k);
    int b = atmostK_odd(nums, k - 1);

    return a - b;
}

int main()
{
    return 0;
}