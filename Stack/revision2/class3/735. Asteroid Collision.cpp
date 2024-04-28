#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision2(vector<int> &asteroids)
{
    stack<int> st;
    for (int ele : asteroids)
    {
        if (ele < 0)
        {
            while (!st.empty() and st.top() > 0 and abs(ele) > st.top())
            {
                st.pop();
            }
            if (st.empty() or st.top() < 0)
            {
                st.push(ele);
            }
        }
        else
        {
            st.push(ele);
        }
    }
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        int ele = st.top();
        st.pop();
        ans[i] = ele;
    }
    return ans;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int ele : asteroids)
    {
        if (ele > 0 or st.empty() or st.top() < 0)
        {
            st.push(ele);
            continue;
        }

        while (!st.empty() and st.top()>0 and st.top() < abs(ele))
        {
            st.pop();
        }
        if (st.empty() or st.top()<0)
            st.push(ele);
        else if (st.top() == abs(ele))
            st.pop();
    }
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        int ele = st.top();
        st.pop();
        ans[i] = ele;
    }
    return ans;
}

int main()
{
    return 0;
}