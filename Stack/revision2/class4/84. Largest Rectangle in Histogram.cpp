#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    st.push(-1);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 and heights[st.top()] >= heights[i])
        {
            int poppedIdx = st.top();
            st.pop();
            int ht = heights[poppedIdx];
            int wt = (i - st.top()) - 1;
            maxArea = max(maxArea, ht * wt);
        }
        st.push(i);
    }
    while (st.top() != -1)
    {
        int poppedIdx = st.top();
        st.pop();
        int ht = heights[poppedIdx];
        int wt = (n - st.top()) - 1;
        maxArea = max(maxArea, ht * wt);
    }
    return maxArea;
}


int main()
{
    return 0;
}