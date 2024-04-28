#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceHelp(string &text1, string &text2, int idx1, int idx2)
{
    if (idx1 == text1.size() or idx2 == text2.size())
        return 0;
    if (text1[idx1] == text2[idx2])
        return longestCommonSubsequenceHelp(text1, text2, idx1 + 1, idx2 + 1) + 1;
    else
        return max(longestCommonSubsequenceHelp(text1, text2, idx1 + 1, idx2), longestCommonSubsequenceHelp(text1, text2, idx1, idx2 + 1));
}

int longestCommonSubsequence(string text1, string text2)
{
    return longestCommonSubsequenceHelp(text1, text2, 0, 0);
}

int main()
{
    return 0;
}