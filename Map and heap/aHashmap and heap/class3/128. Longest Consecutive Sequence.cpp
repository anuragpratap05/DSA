#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    map<int, int> m;
    for (int e : nums)
    {
        m[e]++;
    }
    int ans = 0;
    for (int e : nums)
    {
        int val1 = e + 1;
        int val2 = e - 1;
        int temp1 = 0;
        int temp2 = 0;
        while (m.find(val1) != m.end())
        {
            temp1++;
            // ans=max(ans,temp);
            m.erase(val1);
            val1++;
        }
        while (m.find(val2) != m.end())
        {
            temp2++;
            m.erase(val2);
            // ans=max(ans,temp);
            val2--;
        }
        // cout<<e<<endl;
        // cout<<temp1<<" "<<temp2<<endl;
        ans = max(ans, (temp1 + temp2) + 1);
        m.erase(e);
    }
    return ans;
}
int longestConsecutive2(vector<int> &nums)
{
    set<int> s;
    for (int e : nums)
    {
        s.insert(e);
    }
    int ans = 0;
    for (int e : nums)
    {
        if (s.find(e) == s.end())
        {
            continue;
        }
        s.erase(e);
        int ple = e - 1;
        int pre = e + 1;
        while (s.find(ple) != s.end())
        {
            s.erase(ple);
            ple--;
        }
        while (s.find(pre) != s.end())
        {
            s.erase(pre);
            pre++;
        }
        ans = max(ans, pre - ple - 1);
    }
    return ans;
}
int main()
{
    return 0;
}