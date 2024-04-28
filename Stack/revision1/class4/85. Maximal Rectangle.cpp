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
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> vec(m, 0);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(matrix[i][j]=='0')
            {
                vec[j] = 0;
            }
            else{
                vec[j] += matrix[i][j] - '0';
            }
        }
        area = max(area, largestRectangleArea2(vec));
    }
    return area;
}

int main()
{
    return 0;
}