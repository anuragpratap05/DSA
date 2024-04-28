#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> vec;
    map<int, int> m;
    for (int e : nums)
    {
        m[e]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto& p:m)
    {
        pq.push({p.second,p.first});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        vec.push_back(pq.top().second);
        pq.pop();
    }
    return vec;
}

int main()
{
    return 0;
}