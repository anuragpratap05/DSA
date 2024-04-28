#include<bits/stdc++.h>
using namespace std;

//O(Nlog(N))
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        
        for(int i=k;i<n;i++)
        {
            pq.push({nums[i],i});
            int range=i-k+1;
            while(pq.top().second<range)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
    //O(n)
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and nums[dq.back()]<=nums[i])
            {
               dq.pop_back(); 
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++)
        {
            
            int range=i-k+1;
            while(!dq.empty() and dq.front()<range)
            {
                dq.pop_front();
            }
            while(!dq.empty() and nums[dq.back()]<=nums[i])
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
    return 0;
}