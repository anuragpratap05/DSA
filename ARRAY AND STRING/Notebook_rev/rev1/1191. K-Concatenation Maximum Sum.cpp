#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

int kadanes(vector<int> &nums)
{
    int gsum = -1e9;
    int csum = -1e9;

    for (int ele : nums)
    {
        csum += ele;
        if (ele > csum)
            csum = ele;
        if (csum > gsum)
            gsum = csum;
    }
    return gsum > 0 ? gsum : 0;
}

int prefixSum(vector<int> &nums)
{
    int maxPrefixSum = 0;
    int curSum = 0;

    for (int ele : nums)
    {
        curSum += ele;
        maxPrefixSum = max(maxPrefixSum, curSum);
    }
    return maxPrefixSum;
}

int SuffixSum(vector<int> &nums)
{
    int maxSuffixSum = 0;
    int curSum = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        curSum += nums[i];
        maxSuffixSum = max(maxSuffixSum, curSum);
    }
    return maxSuffixSum;
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{

    int kSum = kadanes(arr);

    if (k == 1)
        return kSum;

    int pSum = prefixSum(arr);
    int sSum = SuffixSum(arr);
    int arrSum = 0;

    for (int ele : arr)
        arrSum += ele;

    if (arrSum < 0)
    {
        return max(kSum, pSum + sSum);
    }
    else
    {
        int bichKaSum = arrSum * (k - 2);
        return max(kSum, pSum + bichKaSum + sSum);
    }
}

int main()
{
    return 0;
}