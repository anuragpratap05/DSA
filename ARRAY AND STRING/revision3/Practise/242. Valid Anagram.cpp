#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    vector<int> freq(26, 0);
    int cnt = 0;
    for (char ch : s)
    {
        cnt++;
        freq[ch - 'a']++;
    }

    for (char ch : t)
    {
        int idx = ch - 'a';
        if (freq[idx] == 0)
            return false;
        freq[idx]--;
        cnt--;
    }
    return cnt == 0;
}

int main()
{
    return 0;
}