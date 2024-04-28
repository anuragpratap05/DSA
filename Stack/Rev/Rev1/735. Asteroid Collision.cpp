#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int ele : asteroids)
    {
        if (st.size() > 0 and st.top() > 0 and ele < 0)
        {
            while (!st.empty() and st.top() > 0 and st.top() < abs(ele))
                st.pop();
            if (st.empty() or st.top() < 0)
                st.push(ele);
            else if (st.top() == abs(ele))
                st.pop();
        }
        else
            st.push(ele);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}