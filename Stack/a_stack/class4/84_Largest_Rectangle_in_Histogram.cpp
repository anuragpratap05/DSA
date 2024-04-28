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
        maxi=max(area,maxi);
    }
    return maxi;
}

//better
int largestRectangleArea2(vector<int> &heights)
{
   stack<int>st;
   int i=0;
   st.push(-1); 
   int n=heights.size();
   int maxi=0;
   while(i<n)
   {
       while(st.top()!=-1 and heights[i]<=heights[st.top()])
       {
           int idx=st.top();
           st.pop();
           int h=heights[idx];
           int w=(i-st.top())-1;
           maxi=max(maxi,h*w); 
       }
       st.push(i);
       i++;
   }
   while(st.top()!=-1)
   {
       int idx = st.top();
       st.pop();
       int h = heights[idx];
       int w = (n - st.top()) - 1;
       maxi = max(maxi, h * w);
   }
   return maxi;
   
}

int main()
{
    vector<int> vec = {8, 6, 5, 6, 7, 7, 7, 7, 6, 5, 4, 2, 10, 7, 6, 8};

    int ans = largestRectangleArea(vec);
    cout << ans;
    return 0;
}