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

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        // cout<<"aya";
        return nums[0];
    }
    if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }
    int with = 0, without = 0;
    int pwith = 0;
    int pwithout = 0;
    int a = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        with = pwithout + nums[i];
        without = max(pwith, pwithout);
        pwith = with;
        pwithout = without;
    }
    int max1 = with;
    int max2 = without;

    with = 0, without = 0;
    pwith = 0;
    pwithout = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        with = pwithout + nums[i];
        without = max(pwith, pwithout);
        pwith = with;
        pwithout = without;
    }
    int max3 = with;

    if (max1 > max3)
    {
        max1 -= a;
    }
    return max(max(max1, max2), max3);
}

int main()
{
    return 0;
}