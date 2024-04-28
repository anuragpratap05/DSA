#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    vector<int> freq(128, 0);
    int p = 0;
    int c = 0;
    int n = s.size();
    int maxLen = 0;
    while (c < n)
    {
        char ch = s[c];
        freq[int(ch)]++;
        if (freq[int(ch)] == 2)
        {
            while (freq[int(ch)] != 1)
            {
                char prevCh = s[p];
                freq[int(prevCh)]--;
                p++;
            }
        }
        c++;
        maxLen = max(maxLen, c - p);
        // cout << maxLen << endl;
    }
    return maxLen;
}

int main()
{
    // char ch = 'a';
    // int x = int(ch);
    // cout << x;
    string s = "abcdbtwmkcxyz";
    cout << lengthOfLongestSubstring(s);
    return 0;
}