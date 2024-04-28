#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int popIdx = 0;
    for (int ele : pushed)
    {
        st.push(ele);
        while (!st.empty() and st.top() == popped[popIdx])
        {
            st.pop();
            popIdx++;
        }
    }
    while (!st.empty() and st.top() == popped[popIdx])
    {
        st.pop();
        popIdx++;
    }
    return st.size() ? false : true;
}

int main()
{
    return 0;
}