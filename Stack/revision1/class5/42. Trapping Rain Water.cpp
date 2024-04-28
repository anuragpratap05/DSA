#include<bits/stdc++.h>
using namespace std;


vector<int> left_big(vector<int>& heights)
{
    vector<int> ans;
    int left_max = heights[0];
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        if(heights[i]>left_max)
        {
            left_max = heights[i];
        }
        ans.push_back(left_max);
    }
    return ans;
}

vector<int> right_big(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n, 0);

    int right_max = heights[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        if (heights[i] > right_max)
        {
            right_max = heights[i];
        }
        ans[i] = right_max;
    }
    return ans;
}

int trap(vector<int> &height)
{
    vector<int> l = left_big(height);
    vector<int> r = right_big(height);

    int ans = 0;

    int n = height.size();
    for (int i = 0; i < n;i++)
    {
        int x = min(l[i], r[i]);
        ans += x - height[i];
    }
    return ans;
}

int trap2(vector<int> &height)
{
    stack<int> st;
    st.push(-1);
    int n = height.size();
    int ans = 0;

    for (int i = 0; i < n;i++)
    {
        int ele = height[i];
        while (st.top() != -1 and height[st.top()]<=ele)
        {
            int idx = st.top();
            st.pop();
            int b = (i - st.top()) - 1;
            int l = min(ele, (st.top() == -1) ? 0 : height[st.top()]);
            l -= height[idx];
            if (l < 0)
            {
                l = 0;
            }
            ans += (b * l);
        }
    }
    return ans;
}

int main()
{
    return 0;
}