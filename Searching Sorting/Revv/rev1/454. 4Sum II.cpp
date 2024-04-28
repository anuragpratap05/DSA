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

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums3.size(); i++)
    {
        for (int j = 0; j < nums4.size(); j++)
        {
            int curSum = nums3[i] + nums4[j];
            mp[curSum]++;
        }
    }
    int cnt = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            int curSum = nums1[i] + nums2[i];
            if (mp.find(0 - curSum) != mp.end())
                cnt += mp[0 - curSum];
        }
    }
    return cnt;
}

int main()
{
    return 0;
}