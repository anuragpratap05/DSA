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

vector<int> NSOR(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while (!st.empty() and nums[st.top()] > ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = n;
        st.pop();
    }
    return ans;
}

vector<int> NSOL(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = nums[i];
        while (!st.empty() and nums[st.top()] > ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> v1 = NSOR(heights);
    vector<int> v2 = NSOL(heights);
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int len = (v1[i] - v2[i]) - 1;
        int b = heights[i];
        area = max(area, len * b);
    }
    return area;
}
// using less space w/o nsol and nsor
int largestRectangleArea2(vector<int> &heights)
{
    stack<int> st;
    st.push(-1);
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int ele = heights[i];
        while (st.top() != -1 and heights[st.top()] >= ele)
        {
            int len = heights[st.top()];
            st.pop();
            int b = (i - st.top()) - 1;
            area = max(area, len * b);
        }
        st.push(i);
    }
    while (st.top() != -1)
    {
        int len = heights[st.top()];
        st.pop();
        int b = (heights.size() - st.top()) - 1;
        area = max(area, len * b);
    }
    return area;
}

int main()
{
    return 0;
}