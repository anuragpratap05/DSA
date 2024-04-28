#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

string minWindow(string s, string t)
{
    int minLen = 1e9;
    if (s.size() == 0 or t.size() == 0)
        return "";
    vector<int> freq(128, 0);

    int strStart = -1, strEnd = -1;

    int cnt = 0;
    for (char ch : t)
    {
        if (++freq[int(ch)] == 1)
            cnt++;
    }

    int cur = 0, p = 0;

    while (cur < s.size())
    {
        char ch = s[cur];
        if (--freq[int(ch)] == 0)
            cnt--;

        while (cnt == 0)
        {
            if ((cur - p) + 1 < minLen)
            {
                strStart = p;
                strEnd = cur;
                minLen = (cur - p) + 1;
            }
            char prevCh = s[p];
            if (++freq[int(prevCh)] == 1)
                cnt++;
            p++;
        }
        cur++;
    }

    if (strStart == -1 or strEnd == -1)
        return "";
    string ans = s.substr(strStart, (strEnd - strStart) + 1);
    return ans;
}

int main()
{
    return 0;
}