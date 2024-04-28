#include <bits/stdc++.h>
using namespace std;

int calculateArea(vector<int> &heights)
{
    stack<int> st;
    st.push(-1);

    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++)
    {
        int curHt = heights[i];
        while (st.top() != -1 and heights[st.top()] >= curHt)
        {
            int h = heights[st.top()];
            st.pop();
            int w = (i - st.top()) - 1;
            int curArea = h < w ? h * h : w * w;
            maxArea = max(maxArea, curArea);
        }
        st.push(i);
    }

    while (st.top() != -1)
    {
        int h = heights[st.top()];
        st.pop();
        int w = (n - st.top()) - 1;
        int curArea = h < w ? h * h : w * w;
        maxArea = max(maxArea, curArea);
    }

    return maxArea;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxArea = 0;

    vector<int> ans(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                ans[j] = 0;
            else
                ans[j] += 1;

        }
        maxArea = max(maxArea, calculateArea(ans));
    }
    return maxArea;
}

int main()
{
    return 0;
}