#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea2(vector<int> &heights)
{
    stack<int> st;
    int i = 0;
    st.push(-1);
    int n = heights.size();
    int maxi = 0;
    while (i < n)
    {
        while (st.top() != -1 and heights[i] <= heights[st.top()])
        {
            int idx = st.top();
            st.pop();
            int h = heights[idx];
            int w = (i - st.top()) - 1;
            maxi = max((h > w ? w * w : h * h), maxi);
        }
        st.push(i);
        i++;
    }
    while (st.top() != -1)
    {
        int idx = st.top();
        st.pop();
        int h = heights[idx];
        int w = (n - st.top()) - 1;
        maxi = max((h > w ? w * w : h * h), maxi);
    }
    return maxi;
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
        maxi = max(maxi, largestRectangleArea2(c));
    }

    return maxi;
}

int maximalSquare2(vector<vector<char>> &matrix)
{
    return maximalRectangle(matrix);
}

int calculateArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    st.push(-1);
    int maxArea = 0;
    // for(int ele:heights)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 and heights[st.top()] >= heights[i])
        {
            int poppedIdx = st.top();
            st.pop();
            int ht = heights[poppedIdx];
            int wt = (i - st.top()) - 1;
            // cout << "ht=" << ht << " , "
            //      << "wt=" << wt << endl;
            maxArea = max(maxArea, ht < wt ? ht * ht : wt * wt);
        }
        st.push(i);
    }
    while (st.top() != -1)
    {
        int poppedIdx = st.top();
        st.pop();
        int ht = heights[poppedIdx];
        int wt = (n - st.top()) - 1;
        // cout << "ht=" << ht << " , "
        //      << "wt=" << wt << endl;
        maxArea = max(maxArea, ht < wt ? ht * ht : wt * wt);
    }
    return maxArea;
}

int maximalSquare(vector<vector<char>> &matrix)
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
    vector<vector<char>> mat = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(mat);
    return 0;
}