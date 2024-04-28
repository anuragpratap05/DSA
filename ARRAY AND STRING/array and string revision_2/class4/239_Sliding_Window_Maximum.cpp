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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0;
    int tempk = k;
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    while (tempk--)
    {
        pq.push({nums[i], i});
        i++;
    }
    i--;
    while (i < nums.size())
    {
        i++;
        int start = i - k;
        while (pq.top().second < start)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
        // push only if there is array element left if condition is imp.
        if (i < nums.size())
            pq.push({nums[i], i});
    }
    return ans;
}

// using deque
vector<int> maxSlidingWindow_btr(vector<int> &nums, int k)
{
    deque<int> dq;
    int i = 0;
    int tempk = k;

    vector<int> ans;
    while (tempk--)
    {
        while (!dq.empty() and nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        i++;
    }
    i--;

    int n = nums.size();
    while (i < n)
    {
        i++;
        int start = i - k;
        while (!dq.empty() and dq.front() < start)
        {
            dq.pop_front();
        }

        ans.push_back(nums[dq.front()]);
        if (i < n)
        {
            while (!dq.empty() and nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1,
                        3,
                        -1,
                        -3,
                        5,
                        3,
                        6,
                        7};
    int k = 3;
    vector<int> x = maxSlidingWindow(nums, k);
    for (int e : x)
    {
        cout << e << " ";
    }
    return 0;
}