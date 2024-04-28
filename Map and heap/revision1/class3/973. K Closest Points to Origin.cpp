#include<bits/stdc++.h>
using namespace std;

double distance(vector<int>& vec)
{
    int x = vec[0];
    int y = vec[1];

    int a = x * x;
    int b = y * y;

    int ans = a + b;
    ans = sqrt(ans);
    return ans;
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>pq;
    int n = points.size();
    for (int i = 0; i < n;i++)
    {
        pq.push({distance(points[i]), i});
    }
    vector<vector<int>> ans;

    while(k--)
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