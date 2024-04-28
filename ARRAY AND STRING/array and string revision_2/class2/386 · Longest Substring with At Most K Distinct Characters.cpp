#include<bits/stdc++.h>
using namespace std;



int lengthOfLongestSubstringKDistinct(string &s, int k)
{
    int n = s.size();
    int cnt = 0;

    vector<int> freq(128, 0);

    int i = 0;
    int p = 0;
    int len = 0;

    while (i < n)
    {
        char ch = s[i];
        if (freq[ch] == 0)
        {
            cnt++;
        }
        freq[ch]++;
        while (cnt > k)
        {
            freq[s[p]]--;
            if (freq[s[p]] == 0)
            {
                cnt--;
            }
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