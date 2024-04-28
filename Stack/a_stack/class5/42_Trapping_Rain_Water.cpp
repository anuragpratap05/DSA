#include <bits/stdc++.h>
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

int trap(vector<int> &height)
{
    int n = height.size();
    int maxleft = height[0];
    vector<int> left_great(n);
    left_great[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (height[i] > maxleft)
        {
            maxleft = height[i];
            left_great[i] = -1;
        }
        else
        {
            left_great[i] = maxleft;
        }
    }

    int maxright = height[n - 1];
    vector<int> right_great(n);
    right_great[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (height[i] < maxright)
        {
            right_great[i] = maxright;
        }
        else
        {
            maxright = height[i];
            right_great[i] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (left_great[i] != -1 and right_great[i] != -1)
        {
            ans += min(left_great[i], right_great[i]);
        }
    }
     return ans;
    for (int e : left_great)
    {
        cout << e << " ";
    }
    cout << endl;
    for (int e : right_great)
    {
        cout << e << " ";
    }

    return 0;
}
// used only stack space
int trap2(vector<int> &height)
{
    stack<int> st;
    int n = height.size();
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        while (!st.empty() and height[st.top()] <= height[i])
        {
            int idx = st.top();
            st.pop();
            if (st.empty())
            {
                // st.push(i);
                // i++;
                // continue;
                ans += 0;
            }
            else
            {
                int w = (i - st.top()) - 1;
                int h = min(height[st.top()], height[i]);

                int area = w * h;

                int rm_area = w * height[idx];
                ans += (area - rm_area);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
//O(1) Space
int trap3(vector<int> &height)
{
    int n=height.size();
    int lmax=0,rmax=0,l=0,r=n-1,ans=0;
    while(l<r)
    {
        lmax=max(lmax,height[l]);
        rmax=max(rmax,height[r] );
        if(height[l]<height[r])
        {
            ans+=(lmax-height[l]);
            l++;
        }
        else{
            ans += (rmax - height[r]);
            r--;
        }
        
    }
    return ans;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> vec ={4, 2, 3};
    vector<int> vec2 = {2,4, 5, 2,3,2,1,0,3,7};
    cout<<trap2(vec2);
    return 0;
}