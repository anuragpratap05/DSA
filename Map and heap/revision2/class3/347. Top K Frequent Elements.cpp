#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    priority_queue<vector<int>> pq;
    for (int ele : nums)
    {
        mp[ele]++;
    }

    for (auto &p : mp)
    {
        pq.push({p.second, p.first});
    }
    vector<int> ans;
    while (k--)
    {
        auto &p = pq.top();
        ans.push_back(p[1]);
    }
    return ans;
}

int main()
{
    return 0;
}