#include <bits/stdc++.h>
using namespace std;
void Display(vector<vector<int>> &myVec)
{
    for (vector<int> &vec : myVec)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << "| ";
    }
    cout << endl;
}
int getSum(vector<int> &vec)
{
    int sum = 0;
    for (int e : vec)
    {
        sum += e;
    }
    return sum;
}

bool canPartitionKSubsetsHelper(vector<int> &nums, int k, int idx, vector<vector<int>> &myVec)
{
    if (idx == nums.size())
    {
        int sum = getSum(myVec[0]);
        for (int itr = 1; itr < k; itr++)
        {
            int newSum = getSum(myVec[itr]);
            if (sum != newSum)
            {
                return false;
            }
        }
        cout << "aya" << endl;
        Display(myVec);

        return true;
    }

    for (int i = 0; i < k; i++)
    {
        int ele = nums[idx];
        myVec[i].push_back(ele);

        bool x = canPartitionKSubsetsHelper(nums, k, idx + 1, myVec);

        myVec[i].pop_back();
        if (myVec[i].size() == 0)
        {
            break;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    vector<vector<int>> myVec(k, vector<int>());
    bool ans = canPartitionKSubsetsHelper(nums, k, 0, myVec);
    // Display(myVec);
    return ans;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    // vector<int> nums = {2, 1, 4, 5, 6};
    // int k = 3;

    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    canPartitionKSubsets(nums, k);
    return 0;
}