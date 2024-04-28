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

vector<int> maxSlidingWindow2(vector<int> &nums, int k)
{
    int i = 0;
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    while (i < k)
    {
        pq.push({nums[i], i});
        i++;
    }
    ans.push_back(pq.top().first);
    while (i < nums.size())
    {
        int lr = i - (k - 1);
        while (!pq.empty() and pq.top().second < lr)
            pq.pop();
        pq.push({nums[i], i});
        ans.push_back(pq.top().first);

        i++;
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<pair<int, int>> dq;
    int i = 0;
    vector<int> ans;

    while (i < k)
    {
        while (!dq.empty() and dq.back().first < nums[i])
            dq.pop_back();
        dq.push_back({nums[i], i});
        i++;
    }
    ans.push_back(dq.front().first);

    while (i < nums.size())
    {
        int lr = i - (k - 1);
        while (!dq.empty() and dq.front().second < lr)
            dq.pop_front();
        while (!dq.empty() and dq.back().first <= nums[i])
            dq.pop_front();
        dq.push_back({nums[i], i});
        ans.push_back(dq.front().first);
        i++;
    }
    return ans;
}

int main()
{
    return 0;
}