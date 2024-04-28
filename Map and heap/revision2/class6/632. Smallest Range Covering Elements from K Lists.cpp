#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int maxEle = INT_MIN;

    for (int listIdx = 0; listIdx < nums.size(); listIdx++)
    {
        int firstEleOfList = nums[listIdx][0];
        pq.push({firstEleOfList, listIdx, 0});
        maxEle = max(maxEle, firstEleOfList);
    }

    int minRange = -1e5;
    int maxRange = 1e5;

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();

        int minEle = vec[0];
        int listIdx = vec[1];
        int col = vec[2];

        if (maxEle - minEle < maxRange - minRange)
        {
            minRange = minEle;
            maxRange = maxEle;
        }

        col++;
        if (col == nums[listIdx].size())
        {
            break;
        }
        int nextEle = nums[listIdx][col];
        pq.push({nextEle, listIdx, col});

        if (nextEle > maxEle)
            maxEle = nextEle;
    }
    return {minRange, maxRange};
}

int main()
{
    return 0;
}