#include<bits/stdc++.h>
using namespace std;



vector<int> NGOR(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> s;
    s.push(0);
    int i = 1;
    while (i < n)
    {
        while (!s.empty() and nums[i] > nums[s.top()])
        {
            ans[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
        i++;
    }
    i=0;
    while (i < n)
    {
        while (!s.empty() and nums[i] > nums[s.top()])
        {
            ans[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
        i++;
    }
    return ans;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    return NGOR(nums);
}

int main()
{
    return 0;
}