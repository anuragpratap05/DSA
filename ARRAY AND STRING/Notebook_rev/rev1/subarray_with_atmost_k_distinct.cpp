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

int Kdistinct(vector<int> &nums, int k)
{
    int subarrays = 0;
    int p = 0, c = 0;

    unordered_map<int, int> freq;
    int cnt = 0;
    while (c < nums.size())
    {
        int ele = nums[c];
        if (++freq[ele] == 1)
            cnt++;
        c++;
        while (cnt > k)
        {
            int pEle = nums[p];
            if (--freq[pEle] == 0)
                cnt--;
            p++;
        }
        subarrays += c - p;
    }
    return subarrays;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 2, 4, 5, 5};
    vector<int> nums = {1, 1, 2, 3};
    int k = 2;
    cout << "distinctCount--> " << Kdistinct(nums, k);
    return 0;
}