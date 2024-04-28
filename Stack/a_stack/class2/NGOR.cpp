#include <bits/stdc++.h>
using namespace std;

vector<int> NGOR(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    int i = 1;
    while (i < n)
    {
        while (!s.empty() and nums[i] > nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i++;
    }
    while (!s.empty())
    {
        ans[s.top()] = n;
        s.pop();
    }
    return ans;
}

vector<int> NGOL(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(n-1);
    int i = n-2;
    while (i >= 0)
    {
        while (!s.empty() and nums[i] > nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i--;
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
}

vector<int> NSOR(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    int i = 1;
    while (i < n)
    {
        while (!s.empty() and nums[i] < nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i++;
    }
    while (!s.empty())
    {
        ans[s.top()] = n;
        s.pop();
    }
    return ans;
}
vector<int> NSOL(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(n - 1);
    int i = n - 2;
    while (i >= 0)
    {
        while (!s.empty() and nums[i] < nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i--;
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};

    vector<int>vec={8,6,5,6,7,7,7,7,6,5,4,2,10,7,6,8};

    vector<int> ans = NSOL(vec);
    for(int e:ans)
    {
        cout<<e<<" ";
    }
    return 0;
}