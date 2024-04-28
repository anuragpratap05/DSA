#include<bits/stdc++.h>
using namespace std;


int atmost_k(vector<int>& nums,int goal)
{
    int n = nums.size();
    int i = 0;
    int p = 0;
    int cnt = 0;
    int sum = 0;

    while(i<n)
    {
        int ele = nums[i];
        sum += ele;
        while(sum>goal)
        {
            int nele = nums[p];
            sum -= nele;
            p++;
        }
        i++;
        cnt += (i - p);
    }
    return cnt;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int a = atmost_k(nums, goal);
    int b = atmost_k(nums, goal)-1;
    return a - b;
}

int main()
{
    return 0;
}