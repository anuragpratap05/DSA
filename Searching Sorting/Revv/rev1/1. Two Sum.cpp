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

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (mp.find(target - ele) != mp.end())
        {
            return {mp[target - ele], i};
        }
        mp[ele] = i;
    }
    return {};
}

int main()
{
    return 0;
}