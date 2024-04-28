#include <bits/stdc++.h>
using namespace std;

int trap2(vector<int> &height)
{
    int n = height.size();
    int largestOnRight = -1;
    int largestOnLeft = -1;
    vector<int> rightVec(n);
    vector<int> leftVec(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            largestOnRight = height[i];
            rightVec[i] = -1;
            continue;
        }
        int curBuildingHt = height[i];
        if (curBuildingHt < largestOnRight)
        {
            rightVec[i] = largestOnRight;
        }
        else
        {
            largestOnRight = height[i];
            rightVec[i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            largestOnLeft = height[i];
            leftVec[i] = -1;
            continue;
        }
        int curBuildingHt = height[i];
        if (curBuildingHt < largestOnLeft)
        {
            leftVec[i] = largestOnLeft;
        }
        else
        {
            largestOnLeft = height[i];
            leftVec[i] = -1;
        }
    }

    int totalWater = 0;
    for (int i = 0; i < n; i++)
    {
        int support = min(leftVec[i], rightVec[i]);
        int selfHt = height[i];
        int waterStored = support - selfHt;
        totalWater += waterStored > 0 ? waterStored : 0;
    }
    return totalWater;
}

int trap(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    st.push(-1);
    int totalWater = 0;
    for (int i = 0; i < n; i++)
    {
        int curHeight = height[i];
        while (st.top() != -1 and height[st.top()] <= curHeight)
        {
            int poppedIdx = st.top();
            st.pop();
            int width = (i - st.top()) - 1;
            int selfHt = height[poppedIdx];
            int support = min(curHeight, st.top() == -1 ? -1 : height[st.top()]);
            int waterStored = (support - selfHt) * width;
            totalWater += waterStored > 0 ? waterStored : 0;
        }
        st.push(i);
    }
    return totalWater;
}

int main()
{
    return 0;
}