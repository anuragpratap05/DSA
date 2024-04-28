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

vector<int> NGOR(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while(!st.empty() and nums[st.top()]<ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = n;
        st.pop();
    }
    return ans;
}


vector<int> NGOL(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n-1; i >=0; i--)
    {
        int ele = nums[i];
        while(!st.empty() and nums[st.top()]<ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}





vector<int> NSOR(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while(!st.empty() and nums[st.top()]>ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = n;
        st.pop();
    }
    return ans;
}


vector<int> NSOL(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n-1; i >=0; i--)
    {
        int ele = nums[i];
        while(!st.empty() and nums[st.top()]>ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};
    vector<int> ans = NSOL(nums);
    for(int e:ans)
    {
        cout << e << " ";
    }
    return 0;
}