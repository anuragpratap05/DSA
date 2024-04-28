#include <bits/stdc++.h>
using namespace std;

int wordBreakHelper(string A, unordered_set<string> &st, int maxLen, int idx)
{
    if (idx == A.size())
    {
        return 1;
    }
    string ans = "";

    for (int i = idx; i < maxLen + idx; i++)
    {
        ans += A[i];
        if (st.find(ans) != st.end())
        {
            int recAns = wordBreakHelper(A, st, maxLen, i + 1);
            if (recAns == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> st;
    int maxLen = 0;
    for (string str : B)
    {
        st.insert(str);
        int len = str.size();
        maxLen = max(maxLen, len);
    }
    return wordBreakHelper(A, st, maxLen, 0);
}

int main()
{
    return 0;
}