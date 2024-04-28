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

int segregate(vector<int> &nums, int s, int e)
{
    int p = s - 1;
    for (int i = s; i <= e; i++)
    {
        if (nums[i] <= nums[e])
        {
            p++;
            swap(nums[p], nums[i]);
        }
    }
    return p;
}

void quickSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
        return;

    int p = segregate(nums, s, e);
    quickSort(nums, s, p - 1);
    quickSort(nums, p + 1, e);
}

vector<int> sortArray(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    return 0;
}