#include <bits/stdc++.h>
using namespace std;
int kDistinctSubarrays(vector<int> &arr, int k)
{
    int arraySize = arr.size();
    int prev = 0, curr = 0, len = 0;
    // vector<int> freq(1e9, 0);
    // unordered_map<int, int> freq;
    int zeroCount = 0;
    int maxLen = 0;
    while (curr < arraySize)
    {
        int ele = arr[curr];
        if (ele == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            int pEle = arr[prev];
            if (pEle == 0)
            {
                zeroCount--;
            }
            prev++;
        }
        curr++;
        maxLen = max(maxLen, (curr - prev));
    }
    return maxLen;
}
int findMaxConsecutiveOnes(vector<int> &nums)
{
    return kDistinctSubarrays(nums, 0);
}

int main()
{
    return 0;
}