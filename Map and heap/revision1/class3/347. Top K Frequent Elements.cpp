#include<bits/stdc++.h>
using namespace std;

// doubt: & operator lgane se glt ans aa rha h

class compa
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return b.second > a.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int e : nums)
    {
        m[e]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compa> pq;
    for (auto &p : m)
    {

        pq.push(p);
    }

    vector<int> ans;
    while (k--)
    {
        auto p = pq.top(); // auto &p = pq.top(); = glt ans
        pq.pop();
        ans.push_back(p.first);
    }
    return ans;
}

int main()
{
    return 0;
}