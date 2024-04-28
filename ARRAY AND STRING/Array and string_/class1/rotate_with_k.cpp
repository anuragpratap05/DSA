#include<bits/stdc++.h>
using namespace std;
void reversed(vector<int>& nums,int i,int j)
{
    while(i<j)
    {
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}


void rotate_by_right(vector<int>& nums, int r)
{
    int n=nums.size();
    r=r%n;
    if(r<0)
    {
        r+=n;
    }
    reversed(nums,0,n-1);
    reversed(nums,0,r-1);
    reversed(nums,r,n-1);
}

void segregate_even_odd(vector<int>& nums)
{
    int n=nums.size();
    int itr=0;
    int pt=-1;
    while(itr<n)
    {
        if(nums[itr]<0)
        {
            swap(nums[++pt],nums[itr]);
        }
        itr++;
    }
}

void segregate_zero_one(vector<int>& nums)
{
    int n=nums.size();
    int itr=0;
    int pt=-1;
    while(itr<n)
    {
        if(nums[itr]==0)
        {
            swap(nums[++pt],nums[itr]);
        }
        itr++;
    }
}


void segregate_zero_one_two(vector<int>& nums)
{
    int n=nums.size();
    int itr=0;
    int pt1=-1;
    int pt2=n;
    while(pt2!=itr)
    {
        if(nums[itr]==0)
        {
            swap(nums[++pt1],nums[itr]);
            itr++;
        }
        else if(nums[itr]==1)
        {
            itr++;
        }
        else{
            swap(nums[--pt2],nums[itr]);
        }
        
    }
    for(int e:nums)
    {
        cout<<e<<" ";
    }

}



int main()
{
    vector<int> vec={0,1,0,2,0,1,1,0,0,0,1,2,0,2};
    vector<int> nums={8,3,1,2};
    for(int i=0;i<nums.size();i++)
    {
        rotate_by_right(nums,i);
        for(int e:nums)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    
   // segregate_zero_one_two(vec);
    return 0;
}