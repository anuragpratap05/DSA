#include<bits/stdc++.h>
using namespace std;

int perfect_insert_pos(vector<int> arr,int tar)
{
    int n=arr.size();
    int si=0;
    int ei=n-1;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        if(arr[mid]<=tar)
        {
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }

    }
    return si;
}

int last_index_if_ele_ispressent(vector<int> arr,int tar)
{
    int insert_pos=perfect_insert_pos(arr,tar);

    int last_index=insert_pos-1;

    if(last_index>=0 and arr[last_index]==tar)
    {
        return last_index;
    }
    else
    {
        return insert_pos;
    }
}
int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    if(n<=1)
    {
        return n;

    }

    vector<int> arr;
    for(int ele:nums)
    {
        int idx=last_index_if_ele_ispressent(arr,ele);
        if(idx==arr.size())
        {
            arr.push_back(ele);
        }
        else
        {
            arr[idx]=ele;
        }

    }
    return arr.size();


}

int main()
{
    return 0;
}