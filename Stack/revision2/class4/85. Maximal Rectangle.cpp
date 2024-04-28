#include <bits/stdc++.h>
using namespace std;

int calculateArea(vector<int> &heights)
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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> c(m, 0);

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        c.resize(m, 0);
        for (int j = 0; j < m; j++)
        {
            char ch = matrix[i][j];
            if (ch == '0')
            {
                c[j] = 0;
            }
            else
            {
                c[j] += 1;
            }
        }
        maxi = max(maxi, calculateArea(c));
    }

    return maxi;
}

int main()
{
    return 0;
}