#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

// numbers of subarrays that can be made which have atmost k different integers
void atmost_k_distinct(vector<int>& nums,int k)
{
    int n=nums.size();
    int ei,si;
    ei=si=0;
    int c=0;
    int count=0;
    vector<int> freq(8,0);
    while(ei<n)
    {
        //cout<<nums[ei]<<" ";
        //cout<<"freq[3]="<<freq[3]<<endl;
        if(freq[nums[ei]]==0)
        {
           // cout<<"aya";
            c++;
            //cout<<"c="<<c<<endl;
        }
        freq[nums[ei]]++;
        ei++;
        
        while(c>k)
        {
            //cout<<"aya";
            freq[nums[si]]--;
            if(freq[nums[si]]==0)
            {
                c--;
            }
            si++;
        }
        count+=ei-si;
    }
}

int main()
{
    vector<int> vec={2,3,3,5,1,5,1,4,5,2,7,4,6,2,3};
    atmost_k_distinct(vec,4);
    return 0;
}