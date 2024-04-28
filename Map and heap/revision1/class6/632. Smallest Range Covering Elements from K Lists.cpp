#include <bits/stdc++.h>
using namespace std;
// Lc pe pass ho gya

// Smallest range in K lists Hard----> GFG(TLE)

vector<int>smallestRange(vector<vector<int>> &nums)
{
    int n = nums.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int maxi = -(1e5);
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i][0]);
        pq.push({nums[i][0], i, 0});
    }

    int ov_mini = 1e5;
    int ov_maxi = -(1e5);

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int val = vec[0];
        int i = vec[1];
        int j = vec[2];

        if (abs(maxi - val) < abs(ov_maxi - ov_mini))
        {
            ov_mini = val;
            ov_maxi = maxi;
        }
        j++;

        if (j < nums[i].size())
        {

            maxi = max(maxi, nums[i][j]);
            pq.push({nums[i][j], i, j});
        }
        else
        {
            return {ov_mini, ov_maxi};
        }
    }
    return {ov_mini, ov_maxi};
}
int main()
{
    return 0;
}