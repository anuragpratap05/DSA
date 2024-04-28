#include <bits/stdc++.h>
using namespace std;
// nhi hua

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

void display(vector<vector<int>> &vec)
{
    for (vector<int> &arr : vec)
    {
        cout << "(" << arr[0] << "," << arr[1] << ") " << endl;
    }
}

int lengthOfLisTabu(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int prevIncSub = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j][0] < nums[i][0] and nums[j][1] < nums[i][1])
                prevIncSub = max(prevIncSub, dp[j]);
        }
        dp[i] = prevIncSub + 1;
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int searchInsert(vector<vector<int>> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (target > nums[mid][0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}
int lengthOfLIS(vector<vector<int>> &nums)
{
    vector<vector<int>> lisVec;
    // lisVec.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        // if (i > 0 and nums[i - 1][1] == nums[i][1])
        //     continue;
        int insertPos = searchInsert(lisVec, nums[i][0]);
        // cout << "insertPos-->" << insertPos << endl;
        if (insertPos == lisVec.size())
        {
            if (lisVec.size() == 0)
            {
                lisVec.push_back(nums[i]);
            }
            else
            {
                if (lisVec[lisVec.size() - 1][1] < nums[i][1])
                    lisVec.push_back(nums[i]);
            }
        }
        else
        {
            if (lisVec[insertPos][0] == nums[i][0] and lisVec[insertPos][1] < nums[i][1])
            {
                continue;
            }
            lisVec[insertPos] = nums[i];
        }
    }
    return lisVec.size();
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
         { 
            // if(a[1]==b[1])
            //     return a[0] < b[0];
            return a[1] < b[1]; });

    display(envelopes);

    return lengthOfLIS(envelopes);
}

int main()
{
    // vector<vector<int>> envelopes = {{2, 3}, {5, 4}, {6, 4}, {7, 7}};
    // vector<vector<int>> envelopes = {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 5}, {5, 5}, {5, 6}, {6, 7}, {7, 8}};
    vector<vector<int>> envelopes = {{6, 10}, {11, 14}, {6, 1}, {16, 18}, {12, 15}, {13, 2}};
    int ans = maxEnvelopes(envelopes);
    cout << "ans--> " << ans << endl;
    // display(envelopes);
    return 0;
}