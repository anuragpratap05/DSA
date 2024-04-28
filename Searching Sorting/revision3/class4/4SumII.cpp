#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
void prepareHashMap(vector<int> &nums3, vector<int> &nums4)
{
    int n = nums3.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = nums3[i] + nums4[j];
            mp[sum]++;
        }
    }
}

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    prepareHashMap(nums3, nums4);

    int n = nums1.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = nums1[i] + nums2[j];
            int reducedTarget = 0 - sum;
            if (mp.find(reducedTarget) != mp.end())
            {
                cnt += mp[reducedTarget];
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}