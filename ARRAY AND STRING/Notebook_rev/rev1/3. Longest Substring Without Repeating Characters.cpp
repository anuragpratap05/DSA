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

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int maxLen = 0;
    if (n == 0)
        return maxLen;

    vector<int> freq(127, 0);
    int c = 0, p = 0;
    while (c < n)
    {
        char ch = s[c];
        freq[int(ch)]++;

        while (freq[int(ch)] == 2)
        {
            // char prevCh = s[p];
            freq[int(s[p++])]--;
            // p++;
        }
        c++;
        maxLen = max(maxLen, (c - p));
    }
    return maxLen;
}

int main()
{
    return 0;
}