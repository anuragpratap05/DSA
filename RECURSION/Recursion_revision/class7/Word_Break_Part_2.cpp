#include <bits/stdc++.h>
using namespace std;

int wordBreakHelper(string A, unordered_set<string> &st, int maxLen, int idx, vector<string> &vec, string psf)
{
    if (idx == A.size())
    {
        vec.push_back(psf);
        return 1;
    }
    string ans = "";
    int cnt = 0;
    for (int i = idx; i < maxLen + idx; i++)
    {
        ans += A[i];
        if (st.find(ans) != st.end())
        {
            string x = psf + ans;
            // psf+=ans;

            if (i != A.size() - 1)
            {
                x += " ";
            }
            // cout<<psf<<endl;
            cnt += wordBreakHelper(A, st, maxLen, i + 1, vec, x);
        }
    }
    return cnt;
}

vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    unordered_set<string> st;
    int maxLen = 0;
    for (string str : dict)
    {
        st.insert(str);
        int len = str.size();
        maxLen = max(maxLen, len);
    }
    vector<string> ans;

    wordBreakHelper(s, st, maxLen, 0, ans, "");
    return ans;
}

int main()
{
    string s = "catsanddog";
    vector<string> dict = {"cats",
                           "cat",
                           "and",
                           "sand",
                           "dog"};
    int n = 5;
    vector<string> ans = wordBreak(n, dict, s);
    for (string str : ans)
    {
        cout << str << endl;
    }
    return 0;
}