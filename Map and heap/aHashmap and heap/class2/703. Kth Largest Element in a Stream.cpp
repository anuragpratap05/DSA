#include<bits/stdc++.h>
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

class KthLargest
{

public:
    priority_queue<int, vector<int>, greater<vector<int>>>pq;
    int x;
    KthLargest(int k, vector<int> &nums)
    {
        x=k;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        
        
    }

    int add(int val)
    {
        pq.push(val);
        if(pq.size()>x)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    return 0;
}