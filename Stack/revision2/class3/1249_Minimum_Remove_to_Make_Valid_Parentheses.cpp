#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else if (ch == ')')
        {
            if (!st.empty() and s[st.top()] == '(')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    // while(!st.empty())
    // {
    //     int idx = st.top();
    //     st.pop();
    //     cout << idx << endl;
    // }

    vector<int> defaultIdxs(st.size());
    int itr = st.size() - 1;
    while (!st.empty())
    {
        int idx = st.top();
        st.pop();
        cout << idx << endl;
        defaultIdxs[itr] = idx;
        itr--;
        // defaultIdxs.push_back(idx);
    }

    string ans = "";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (cnt < defaultIdxs.size() and i == defaultIdxs[cnt])
        {
            cnt++;
            continue;
        }
        ans += s[i];
    }
    return ans;
    return "";
}

int main()
{
    string s = "lee(t(c)o)de)";
    minRemoveToMakeValid(s);
    return 0;
}