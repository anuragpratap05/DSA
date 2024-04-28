#include <bits/stdc++.h>
using namespace std;
vector<int> NSOR(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    int i = 1;
    while (i < n)
    {
        while (!s.empty() and nums[i] < nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i++;
    }
    while (!s.empty())
    {
        ans[s.top()] = n;
        s.pop();
    }
    return ans;
}

vector<int> NSOL(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(n - 1);
    int i = n - 2;
    while (i >= 0)
    {
        while (!s.empty() and nums[i] < nums[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i--;
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }

    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> vec1 = NSOL(heights);
    vector<int> vec2 = NSOR(heights);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int area = heights[i] * (((i - vec1[i]) + (vec2[i] - i)) - 1);
        maxi = max(area, maxi);
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
   // vector<int> p(m, 0);
    vector<int> c(m, 0);

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        // c.clear();
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
        // for(int x=0;x<c.size();x++)
        // {
        //     cout<<c[x]<<" ";
        // }
        // cout<<endl;
        maxi = max(maxi, largestRectangleArea(c));
        // for(int x=0;x<c.size();x++)
        // {
        //     p[x]=c[x];
        // }
    }

    return maxi;
}

int main()
{
    return 0;
}