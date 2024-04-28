#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // return 0;
    int n = s.size();
    vector<int> freq(128, 0);
    int i = 0;
    int p = 0;
    int len = 0;
    while (i < n)
    {
        char ch = s[i];

        freq[ch]++;
        while (freq[ch] > 1)
        {
            freq[s[p]]--;
            p++;
        }
        i++;
        len = max(len, i - p);
    }
    return len;
}

int main()
{
    return 0;
}