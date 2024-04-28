#include <bits/stdc++.h>
using namespace std;


int help_me_with_count(unordered_map<int, int> &m, int k)
{
    int tempk = k;
    int c = 0;
    while (m.find(tempk--) != m.end())
    {
        c++;
        m[tempk]--;
        if (m[tempk] == 0)
        {
            m.erase(tempk);
        }
    }
    tempk = k + 1;
    while (m.find(tempk++) != m.end())
    {
        c++;
        m[tempk]--;
        if (m[tempk] == 0)
        {
            m.erase(tempk);
        }
    }
    return c;
}

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int e : nums)
    {
        m[e]++;
    }
    int ans = 0;

    for (auto &key : m)
    {
        int k = key.first;
        int val = key.second;

        ans = max(ans, help_me_with_count(m, k));
    }
    return ans;
}

int main()
{

    return 0;
}