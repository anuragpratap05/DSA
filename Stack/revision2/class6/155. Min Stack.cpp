#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    // ele,minEle
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty() or val < st.top().second)
            st.push({val, val});
        else
            st.push({val, st.top().second});
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