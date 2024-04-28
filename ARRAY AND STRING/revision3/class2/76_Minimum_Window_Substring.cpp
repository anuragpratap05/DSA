#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> freq(128, 0);
    int cnt = 0;
    for (char ch : t)
    {
        int idx = int(ch);
        if (++freq[idx] == 1)
            cnt++;
    }
    int n = s.size();
    int p = 0;
    int c = 0;
    int myS = 0;
    int myE = 0;
    int minlen = 1e7;
    while (c < n)
    {
        char ch = s[c];
        int idx = int(ch);
        if (--freq[idx] == 0)
        {
            cnt--;
        }
        while (cnt == 0)
        {
            char prevCh = s[p];
            int pIdx = int(prevCh);
            if (++freq[pIdx] == 1)
            {
                cnt++;
            }
            // minlen = min(minlen, (c + 1 - p));
            if ((c + 1 - p) < minlen)
            {
                minlen = (c + 1 - p);
                myS = p;
                myE = c + 1;
            }
            p++;
        }
        c++;
    }
    if (minlen == 1e7)
    {
        return "";
    }
    return s.substr(myS, minlen);
    // return minlen;
}

int main()
{
    cout << minWindow("aa", "aa");
    return 0;
}