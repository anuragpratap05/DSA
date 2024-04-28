#include <bits/stdc++.h>
using namespace std;

vector<int> ngol(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
            maxi = nums[i];
        else
            ans[i] = maxi;
        // ans.push_back(maxi);
        // if (nums[i] > maxi)
        //     maxi = nums[i];
    }
    return ans;
}

vector<int> ngor(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int maxi = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            maxi = nums[i];
        }
        else
        {
            ans[i] = maxi;
        }
        // ans.push_back(maxi);
        // if (nums[i] > maxi)
        //     maxi = nums[i];
    }
    return ans;
}

int trap(vector<int> &height)
{

    vector<int> leftMax = ngol(height);
    vector<int> rightMax = ngor(height);
    int water = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int minSupport = min(leftMax[i], rightMax[i]);
        int curHt = height[i];

        water += minSupport - curHt > 0 ? minSupport - curHt : 0;
    }
    return water;
}

int trap2(vector<int> &height)
{
    stack<int> st;
    st.push(-1);
    int water = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int curHt = height[i];
        while (st.top() != -1 and height[st.top()] <= curHt)
        {
            int popIdx = st.top();
            st.pop();
            int popHt = height[popIdx];
            int width = (i - st.top()) - 1;
            int minSupport = st.top() == -1 ? 0 : min(curHt, height[st.top()]);
            water += minSupport - curHt < 0 ? 0 : (minSupport - curHt) * width;
        }
    }
    return water;
}
int main()
{
    return 0;
}