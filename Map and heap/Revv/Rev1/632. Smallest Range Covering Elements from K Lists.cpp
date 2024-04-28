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
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<vector<int>>>> pq;
    int minRange = -1e7, maxrange = 1e7;

    int maxEle = -1e7;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i][0], i, 0});
        maxEle = max(maxEle, nums[i][0]);
    }

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int minEle = vec[0];
        int i = vec[1];
        int j = vec[2];

        if (maxEle - minEle < maxrange - minRange)
        {
            minRange = minEle;
            maxrange = maxEle;
        }

        j++;
        if (j >= nums[i].size())
            break;

        pq.push({nums[i][j], i, j});
        if (nums[i][j] > maxEle)
            maxEle = nums[i][j];
    }
    return {minRange, maxrange};
}

int main()
{
    return 0;
}