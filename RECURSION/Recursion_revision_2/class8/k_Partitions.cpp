#include <bits/stdc++.h>
using namespace std;

int vectorSum(vector<int> &vec)
{
    int sum = 0;
    for (int e : vec)
    {
        sum += e;
    }
    return sum;
}

bool isSubsetSumEqual(vector<vector<int>> &ans, int k)
{
    int expectedSum = vectorSum(ans[0]);
    for (int i = 1; i < k; i++)
    {
        int curSum = vectorSum(ans[i]);
        if (curSum != expectedSum)
        {
            return false;
        }
    }
    return true;
}

void display(vector<vector<int>> &ans)
{
    for (vector<int> &vec : ans)
    {
        cout << "[";
        for (int i = 0; i < vec.size(); i++)
        {
            int e = vec[i];
            cout << e;
            if (i < vec.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

int kPartitionHelper(vector<int> &nums, int k, vector<vector<int>> &ans, int idx)
{
    if (idx == nums.size())
    {
        if (isSubsetSumEqual(ans, k))
        {
            display(ans);
            return 1;
        }
        return 0;
    }

    int curNum = nums[idx];
    int cnt = 0;

    for (vector<int> &vec : ans)
    {
        vec.push_back(curNum);
        cnt += kPartitionHelper(nums, k, ans, idx + 1);
        vec.pop_back();
        if (vec.size() == 0)
        {
            break;
        }
    }
    return cnt;
}

int kPartition(vector<int> &nums, int k)
{
    vector<vector<int>> ans(k, vector<int>());
    return kPartitionHelper(nums, k, ans, 0);
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    // int k = 3;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> k;
    kPartition(nums, k);
    return 0;
}