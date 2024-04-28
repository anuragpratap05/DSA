#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];

        while (!st.empty() and ele > nums[st.top()])
        {
            ans[st.top()] = ele;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while (!st.empty() and ele > nums[st.top()])
        {
            ans[st.top()] = ele;
            st.pop();
        }
    }
    return ans;
}

int main()
{
    return 0;
}