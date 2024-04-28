#include <bits/stdc++.h>
using namespace std;

int atmostK_distinct(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int n = nums.size();
    int i = 0;
    int p = 0;
    int len = 0;
    int cnt = 0;
    vector<int> freq(20001, 0);
    while (i < n)
    {
        int ele = nums[i];
        if (freq[ele] == 0)
        {
            cnt++;
        }
        freq[ele]++;

        while (cnt > k)
        {
            int nele = nums[p];
            freq[nele]--;
            if (freq[nele] == 0)
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


int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int a = atmostK_distinct(nums, k);
    int b = atmostK_distinct(nums, k - 1);

    return a - b;
}

int main()
{
    return 0;
}