#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s)
{
    vector<int> freq(128, 0);
    int p = 0;
    int c = 0;
    int n = s.size();
    int maxLen = 0;
    int cnt = 0;
    while (c < n)
    {
        char ch = s[c];
        freq[int(ch)]++;
        if (freq[int(ch)] == 1)
        {
            cnt++;
        }

        while (cnt > 2)
        {
            char prevCh = s[p];
            freq[int(prevCh)]--;
            p++;
            if (freq[int(prevCh)] == 0)
            {
                cnt--;
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
    string s = "eceba";
    cout << lengthOfLongestSubstringTwoDistinct(s);
    return 0;
}