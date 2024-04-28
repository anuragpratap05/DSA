#include<bits/stdc++.h>
using namespace std;


 int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        map<int,int> m;
        m[0]=-1;
        int ei=0;
        int sum=0;
        int len=0;
        
        while(ei<n)
        {
            sum+=nums[ei];
            if(m.find(sum)==m.end())
            {
                m[sum]=ei;
            }
            else
            {
                len=max(len,ei-m[sum]);
                //m[sum]++;
            }
            ei++;
        }
        return len;
    }

int main()
{
    return 0;
}