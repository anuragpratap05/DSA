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

int kadanes(vector<int> &nums)
{
    int gsum = -1e9;
    int csum = -1e9;

    for (int ele : nums)
    {
        csum += ele;
        if (ele > csum)
            csum = ele;
        if (csum > gsum)
            gsum = csum;
    }
    return gsum > 0 ? gsum : 0;
}

int main()
{
    // vector<int> nums = {-3, -5, -2, -1, -6, -8};
    // vector<int> nums = {-1, 5, 3, -5, -3, 2, 4};
    vector<int> nums = {-2, -3, 2};
    cout << "max-->  " << kadanes(nums) << endl;
    return 0;
}