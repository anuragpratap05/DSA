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

int searchInsert(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> vec;

    for (int ele : nums)
    {
        int idx = searchInsert(vec, ele);
        if (idx == vec.size())
        {
            vec.push_back(ele);
        }
        else
        {
            vec[idx] = ele;
        }
    }
    return vec.size();
}

int main()
{
    return 0;
}