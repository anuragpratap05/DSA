#include<bits/stdc++.h>
using namespace std;

int minWindow(string s, string t)
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
        return 0;
    }
    return len;
}

int findSubString(string str)
{
    unordered_set<char> s;
    for(auto ch:str)
    {
        s.insert(ch);
    }
    string t = "";
    for(auto ch:s)
    {
        t += ch;
    }
    return minWindow(str, t);
}

int main()
{
    return 0;
}