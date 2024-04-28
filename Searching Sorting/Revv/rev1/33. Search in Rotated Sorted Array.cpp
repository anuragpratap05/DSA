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

int search(vector<int> &nums, int target)
{
    int targetIdx = -1;
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[s] <= nums[mid])
        {
            if (target >= nums[s] and target <= nums[mid])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid + 1] and target <= nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
    }

    return targetIdx;
}

int main()
{
    return 0;
}