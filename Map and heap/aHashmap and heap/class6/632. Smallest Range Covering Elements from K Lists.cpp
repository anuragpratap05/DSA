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

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int maxi = INT_MIN;
    int left = -(1e5);
    int right = (1e5);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i][0]);
        pq.push({nums[i][0], i, 0});
    }
    int mini;
    while (!pq.empty())
    {
        vector<int> v = pq.top();
        pq.pop();
        mini = v[0];
        int r = v[1];
        int c = v[2];
        c++;
        if (maxi - mini < right - left)
        {
            left = mini;
            right = maxi;
        }
        if (c >= nums[r].size())
        {
            break;
        }

        pq.push({nums[r][c], r, c});
        maxi = max(maxi, nums[r][c]);
    }
    return {left, right};
}

int main()
{
    return 0;
}