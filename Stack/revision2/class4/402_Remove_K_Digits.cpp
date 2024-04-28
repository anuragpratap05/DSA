#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;
    for (char ch : num)
    {
        while (!st.empty() and ch < st.top() and k > 0)
        {
            st.pop();
            k--;
        }
        st.push(ch);
    }

    while (k-- and !st.empty())
    {
        st.pop();
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    int itr = 0;
    while (itr < ans.size() and ans[itr] == '0')
    {
        itr++;
    }
    string finalAns = "";
    for (int i = itr; i < ans.size(); i++)
    {
        finalAns += ans[i];
    }
    return finalAns.size() == 0 ? "0" : finalAns;
}
int main()
{
    return 0;
}