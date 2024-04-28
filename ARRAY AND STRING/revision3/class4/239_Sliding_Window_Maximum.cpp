#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }

    ans.push_back(pq.top().first);

    for (int i = k; i < nums.size(); i++)
    {
        int start = i - k;
        while (!pq.empty() and pq.top().second <= start)
        {
            pq.pop();
        }
        pq.push({nums[i], i});
        ans.push_back(pq.top().first);
    }
    return ans;
}

// using dq
vector<int> maxSlidingWindow2(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    for (int i = k; i < nums.size(); i++)
    {
        int start = i - k;
        while (!dq.empty() and dq.front() <= start)
        {
            dq.pop_front();
        }
        int curEle = nums[i];
        while (!dq.empty() and nums[dq.back()] <= curEle)
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    return 0;
}