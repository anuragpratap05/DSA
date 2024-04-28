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

int subarraysDivByK(vector<int> &nums, int k)
{
    vector<int> freq(10001);
    freq[0] = 1;
    int csum = 0;
    int i = 0;
    int n = nums.size();
    int cnt = 0;
    while (i < n)
    {
        int ele = nums[i];
        csum += ele;
        int rem = csum % k;
        if (rem < 0)
        {
            rem = rem + k;
        }
        cnt += freq[rem];
        freq[rem]++;
        i++;
    }
    return cnt;
}

int main()
{
    return 0;
}