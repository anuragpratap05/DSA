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

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1;
    int target = k;
    int curSum = 0;
    int subArrayCnt = 0;
    for (int ele : nums)
    {
        curSum += ele;
        if (freq.find(curSum - target) != freq.end())
            subArrayCnt += freq[curSum - target];
        freq[curSum]++;
    }
    return subArrayCnt;
}

int main()
{
    return 0;
}