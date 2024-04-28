#include <bits/stdc++.h>
using namespace std;

int distance(vector<int> &point)
{
    int x = point[0];
    int y = point[1];

    int ans = sqrt((x * x) + (y * y));
    return ans;
}
class comp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first < b.first)
            return a.first < b.first;

        return a.second > b.second;
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < points.size(); i++)
    {
        int dis = distance(points[i]);
        pq.push({dis, i});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while (!pq.empty())
    {
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    return ans;
}

int main()
{
    return 0;
}