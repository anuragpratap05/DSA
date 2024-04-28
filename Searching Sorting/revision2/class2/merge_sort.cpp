#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& nums,int si,int ei,vector<int>& temp)
{
    int mid=(si+ei)/2;
    vector<int>temp(ei-si+1,0);
    int i=si;
    int j=mid+1;
    int k=0;
    
    while(i<=mid and j<=ei)
    {
        if(nums[i]<=nums[j])
        {
            temp[k]=nums[i];
            i++;
            k++;
        }
        else{
            temp[k]=nums[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        temp[k]=nums[i];
            i++;
            k++;
    }

    while(j<=ei)
    {
        temp[k]=nums[j];
            j++;
            k++;
    }
    k=0;
    for(int i=si;i<=ei;i++)
    {
        nums[i]=temp[k];
        k++;
    }
}

void merge_sort(vector<int>& nums,int si,int ei,vector<int>& temp)
{
    if(si>=ei)
    {
        return ;
    }
    int mid=(si+ei)/2;
    merge_sort(nums,si,mid,temp);
    merge_sort(nums,mid+1,ei,temp);
    merge(nums,si,ei,temp);
}

int main()
{
    return 0;
}