#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    int stringLen = s.size();
    int prev = 0;
    int curr = 0;
    int ans = 0;
    int distinctCount = 0;
    vector<int> freq(128, 0);
    while (curr < stringLen)
    {
        char ch = s[curr];
        if (++freq[ch] == 1)
        {
            distinctCount++;
        }
        while (distinctCount > k)
        {
            char prevCh = s[prev];
            if (--freq[prevCh] == 0)
            {
                distinctCount--;
            }
            prev++;
        }
        curr++;
        ans = max(ans, curr - prev);
    }
    return ans;
}

int main()
{
    char ch = 'a';
    int asci = ch;
    cout << asci;
    return 0;
}