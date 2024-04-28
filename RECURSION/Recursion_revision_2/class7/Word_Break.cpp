#include <bits/stdc++.h>
using namespace std;

bool workBreakHelper(string A, unordered_set<string> &st, int maxSize)
{
    if (A.size() == 0)
    {
        return true;
    }
    string curStr = "";
    for (int i = 0; i < maxSize; i++)
    {
        curStr += A[i];
        if (st.find(curStr) != st.end())
        {
            bool ans = workBreakHelper(A.substr(i + 1), st, maxSize);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> st;
    int maxSize = 0;
    for (string str : B)
    {
        st.insert(str);
        int strSize = str.size();
        maxSize = max(maxSize, strSize);
    }
    if (workBreakHelper(A, st, maxSize))
    {
        return 1;
    }
    return 0;
}

int main()
{

    vector<string> vec = {"i",
                          "like",
                          "sam",
                          "sung",
                          "samsung",
                          "mobile",
                          "ice",
                          "cream",
                          "icecream",
                          "man",
                          "go",
                          "mango"};
    string A = "ilikesamsungz";
    cout << wordBreak(A, vec);
    return 0;
}