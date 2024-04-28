#include<bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    int n=nums.size();
    priority_queue<pair<int,int>>pq;
    int i=0;
    for(;i<k;i++)
    {
        pq.push({nums[i],i});
    }        
    vector<int> ans;
    ans.push_back(pq.top().first);
    while(i<n)
    {
        pq.push({nums[i],i});
        i++;
        while(pq.top().second<i-k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;

}
vector<int> maxSlidingWindow_btr(vector<int>& nums, int k)
{
    deque<int> dq;  
    int i=0;
    int n=nums.size();
    vector<int>ans;
    while(i<n)
    {
        int ele=nums[i];
        int range=(i-k)+1;
        while(!dq.empty() and dq.front()<range)
        {
            dq.pop_front();
        }

        while(!dq.empty() and nums[dq.back()]<ele)
        {
            dq.pop_back();
        }

        dq.push_back(i);
        if((i-k)+1>=0)
        {
            ans.push_back(nums[dq.front()]);
        }
        i++;

    }    
    return ans;  
}

int main()
{
    return 0;
}