#include<bits/stdc++.h>
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

int height(vector<int>& nums,int idx)
{
    if(idx>=nums.size())
    {
        return -1;
    }
    int lh = height(nums, idx * 2 + 1);
    int rh = height(nums, idx * 2 + 2);

    return max(lh, rh) + 1;
}

int main()
{
    vector<int> nums = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    cout << height(nums, 0);
    return 0;
}