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

vector<int> NGOR(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while (!st.empty() and nums[st.top()] < ele)
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = n;
        st.pop();
    }
    return ans;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while (!st.empty() and nums[st.top()] < ele)
        {
            ans[st.top()] = ele;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        while (!st.empty() and nums[st.top()] < ele)
        {
            ans[st.top()] = ele;
            st.pop();
        }
        // st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}

int main()
{
    return 0;
}