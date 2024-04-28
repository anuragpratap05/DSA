#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<long, long>> st;
    // long mini=1e13;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int temp = (val < st.top().second ? val : st.top().second);
            st.push({val, temp});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};
int main()
{
    return 0;
}