#include <bits/stdc++.h>
using namespace std;

bool isAnargam(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;

    vector<int> freq(26, 0);

    for (char ch : s1)
        freq[ch - 'a']++;

    for (char ch : s2)
    {
        int idx = ch - 'a';
        if (freq[idx] == 0)
        {
            return false;
        }
        freq[idx]--;
    }
    return true;
}

// O(n^2*l)
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    int n = strs.size();
    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        string &str1 = strs[i];
        if (str1 == ".")
            continue;
        vector<string> sa;
        sa.push_back(str1);
        for (int j = i + 1; j < n; j++)
        {
            string &str2 = strs[j];
            if (str2 == ".")
                continue;
            bool anargam = isAnargam(str1, str2);
            if (anargam)
            {
                sa.push_back(str2);
                strs[j] = ".";
            }
        }
        ans.push_back(sa);
    }
    return ans;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<int>> mp;

    for (int i = 0; i < strs.size(); i++)
    {
        string str = strs[i];
        sort(str.begin(), str.end());
        mp[str].push_back(i);
    }
    vector<vector<string>> ans;
    for (auto &p : mp)
    {
        vector<string> sa;
        for (int idx : p.second)
        {
            sa.push_back(strs[idx]);
        }
        ans.push_back(sa);
    }
    return ans;
}
int main()
{
    // vector<string> strs = {{"eat", "tea", "tan", "ate", "nat", "bat"}};
    vector<string> strs = {{"a"}};
    vector<vector<string>> ans = groupAnagrams(strs);
    cout << ans.size() << endl;
    for (vector<string> &sa : ans)
    {
        for (string &str : sa)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}