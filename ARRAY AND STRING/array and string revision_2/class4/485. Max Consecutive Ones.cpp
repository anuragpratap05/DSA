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

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int zc = 0;
    int i = 0;
    int p = 0;
    int len = 0;
    while (i < n)
    {
        /* code  */
        int ele = nums[i];
        if(ele==0)
        {
            zc++;
        }
        while(zc>0)
        {
            int nele = nums[p];
            if(nele==0)
            {
                zc--;
            }
            p++;
        }
        i++;
        len = max(len, i - p);
    }
    return len;
}

int main()
{
    return 0;
}