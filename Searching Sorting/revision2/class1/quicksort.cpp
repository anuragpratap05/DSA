#include<bits/stdc++.h>
using namespace std;


int segregate(vector<int>& nums,int si,int ei,int pivotidx)
{
    swap(nums[pivotidx],nums[ei]);
    int pivot=nums[ei];
    int p=si-1;
    int itr=si;
    while(itr<=ei)
    {
        if(nums[itr]<=pivot)
        {
            p++;
            swap(nums[p],nums[itr]);
        }
        itr++;
    }
    return p;
}

void quicksort(vector<int>& nums,int si,int ei)
{
    if(si>=ei)
    {
        return ;
    }
    int pivot=(si+ei)/2;
    int p=segregate(nums,si,ei,pivot);
    quicksort(nums,si,p-1);
    quicksort(nums,p+1,ei);
    return;

}

int main()
{
    return 0;
}