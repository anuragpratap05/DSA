#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseqHelp(string &s, int si, int ei)
{
    if (si >= ei)
        return si == ei ? 1 : 0;
    if (s[si] == s[ei])
        return longestPalindromeSubseqHelp(s, si + 1, ei - 1);
    else
        return max(longestPalindromeSubseqHelp(s, si + 1, ei), longestPalindromeSubseqHelp(s, si, ei - 1));
}

int longestPalindromeSubseq(string s)
{
    return longestPalindromeSubseqHelp(s, 0, s.size() - 1);
}

int main()
{
    return 0;
}