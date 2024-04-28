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

int findMaxLength(vector<int> &nums)
{
    int maxLen = 0;
    unordered_map<int, int> freq;
    freq[0] = -1;
    int sumSoFar = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sumSoFar += nums[i] == 0 ? 1 : -1;
        if (freq.find(sumSoFar) == freq.end())
        {
            freq[sumSoFar] = i;
        }
        else
        {
            maxLen = max(maxLen, (i - freq[sumSoFar]) + 1);
        }
    }
    return maxLen;
}

int main()
{
    return 0;
}