#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    // unordered_map<int, int> freq;
    int n = nums.size();
    vector<int> freq(n, 1e6);
    freq[0] = -1;
    int cumSum = 0;
    int maxLen = 0;
    cout << "n=" << n << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (ele == 0)
        {
            cumSum -= 1;
        }
        else
        {
            cumSum += 1;
        }
        // if (cumSum == 0)
        // {
        //     maxLen = max(maxLen, i + 1);
        // }
        // if (freq.find(cumSum) != freq.end())
        // {
        //     maxLen = max(maxLen, i - freq[cumSum]);
        // }
        // else
        // {
        //     freq[cumSum] = i;
        // }
        int mappedCumSum = cumSum < 0 ? n - cumSum : cumSum;
        cout << "mappedCumSum=" << mappedCumSum << endl;
        if (freq[mappedCumSum] != 1e6)
        {
            maxLen = max(maxLen, i - freq[mappedCumSum]);
        }
        else
        {
            freq[mappedCumSum] = i;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {0, 1, 0, 1};
    cout << findMaxLength(nums);
    return 0;
}