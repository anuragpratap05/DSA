#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> freq(128, 0);
    int n = s.size();
    int cnt = 0;
    for (char ch : t)
    {
        if (freq[ch] == 0)
        {
            cnt++;
        }
        freq[ch]++;
    }
    
    int si = 0;

    int i = 0;
    int p = 0;
    int len = INT_MAX;
    ;

    while (i < n)
    {
        char ch = s[i];
        freq[ch]--;
        if (freq[ch] == 0)
        {
            cnt--;
        }
        i++;
        while (cnt == 0)
        {

            
            if (len > i - p)
            {
                len = i - p;
                si = p;
            }

            freq[s[p]]++;
            if (freq[s[p]] > 0)
            {
                cnt++;
            }
            p++;
        }
    }

    if (len == INT_MAX)
    {
        return "";
    }
    return s.substr(si, len);
}
int main()
{
    return 0;
}