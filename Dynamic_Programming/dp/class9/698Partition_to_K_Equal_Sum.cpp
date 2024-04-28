#include <bits/stdc++.h>
using namespace std;

bool canPartitionKSubsetsHelp(vector<int> &nums, vector<int> &setSum, int idx, int equalPart)
{
    if (idx == nums.size())
    {
        int firstSetSum = setSum[0];
        for (int i = 1; i < setSum.size(); i++)
        {
            if (setSum[i] != firstSetSum)
                return false;
        }
        return true;
    }

    bool donePartition = false;

    for (int i = 0; i < setSum.size(); i++)
    {
        if (setSum[i] + nums[idx] <= equalPart)
        {
            setSum[i] += nums[idx];
            donePartition = donePartition || canPartitionKSubsetsHelp(nums, setSum, idx + 1, equalPart);
            setSum[i] -= nums[idx];
            if (setSum[i] == 0)
                break;
        }
    }
    return donePartition;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int arrSum = 0;
    for (int ele : nums)
        arrSum += ele;

    if (arrSum % k != 0)
        return false;
    int equalPart = arrSum / k;
    vector<int> setSum(k, 0);
    return canPartitionKSubsetsHelp(nums, setSum, 0, equalPart);
}

int main()
{
    vector<int> nums = {3, 4, 5, 6};
    int k = 3;
    bool ans = canPartitionKSubsets(nums, k);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}