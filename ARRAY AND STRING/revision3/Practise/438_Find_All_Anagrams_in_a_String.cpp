#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string &t)
{
    // cout << "s= " << s << " p= " << t << endl;
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

bool isAnagramRange(string &s, string &t, int start, int end)
{
    // cout << "s= " << s << " p= " << t << endl;
    vector<int> freq(26, 0);
    int cnt = 0;
    // for (char ch : s)
    // {
    //     cnt++;
    //     freq[ch - 'a']++;
    // }

    for (int i = start; i <= end; i++)
    {
        char ch = s[i];
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

bool compareHashes(vector<int> &sHash, vector<int> &pHash)
{
    for (int i = 0; i < sHash.size(); i++)
    {
        if (sHash[i] != pHash[i])
            return false;
    }
    return true;
}

vector<int> findAnagramsOptimized(string &s, string &p)
{

    vector<int> ans;

    vector<int> sHash(26, 0);
    vector<int> pHash(26, 0);

    for (char ch : p)
        pHash[ch - 'a']++;

    for (int i = 0; i < p.size(); i++)
    {
        char ch = s[i];
        sHash[ch - 'a']++;
    }

    if (compareHashes(sHash, pHash))
        ans.push_back(0);
    int si = 0, ei = p.size() - 1;

    char ch = s[si];
    sHash[ch - 'a']--;
    si++;
    ei++;

    while (ei < s.size())
    {
        char ch = s[ei];
        sHash[ch - 'a']++;
        if (compareHashes(sHash, pHash))
            ans.push_back(si);
        sHash[s[si] - 'a']--;
        si++;
        ei++;
    }
    return ans;
}

vector<int> findAnagrams(string &s, string &p)
{
    if (p.size() > s.size())
        return {};
    return findAnagramsOptimized(s, p);
    // vector<int> indexes;
    // for (int i = 0; i <= (s.size() - p.size()); i++)
    // {

    //     if (isAnagramRange(s, p, i, i + (p.size() - 1)))
    //         indexes.push_back(i);
    // }
    // return indexes;
}

int main()
{
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for (int ele : ans)
        cout << ele << " ";
    return 0;
}