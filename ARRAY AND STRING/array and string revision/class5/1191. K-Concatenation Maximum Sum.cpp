#include<bits/stdc++.h>
using namespace std;


    long long  kadans_postve(vector<int>& nums)
{
    // this will give ans 0 if there are all neg nums

    long long csum=0;
    long long  gsum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int ele=nums[i];
        csum+=ele%1000000007;
        if(csum>gsum)
        {
            gsum=csum;
        }
        if(csum<0)
        {
            csum=0;
        }
    }
    return gsum;
}
vector<long long> kadans_pos_subarray(vector<int>& nums)
{
    // this will give ans 0 if there are all neg nums
    long long csum=0;
    long long gsum=0;
    int n=nums.size();
    long long si=0;
    long long ei=0;
    long long csi=0;
    for(int i=0;i<n;i++)
    {
        int ele=nums[i];
        csum+=ele;
        csum%=1000000007;
        if(csum>gsum)
        {
            si=csi;
            ei=i;
            gsum=csum;
        }
        if(csum<0)
        {
            csi=i+1;
            csum=0;
        }
    }
    return {gsum,si,ei};
}

int kConcatenationMaxSum(vector<int>& arr, int k)
{
    long long array_sum=0;
    vector<int>k2;
    int n=arr.size();
    if(k==1)
    {
        return kadans_postve(arr)%1000000007;
    }
    
    for(int ele:arr)
    {
        k2.push_back(ele);
        array_sum+=ele;
    }
    for(int ele:arr)
    {
        k2.push_back(ele);
        //array_sum+=ele;
    }
    if(array_sum<=0 or k==2)
    {
        return kadans_postve(k2)%1000000007;
    }
    //long long ans1=(array_sum*k)%1000000007;
    long long ans2=kadans_postve(arr)%1000000007;

    vector<long long>vec=kadans_pos_subarray(arr);
    //vector<int>vec1=kadans_pos_subarray(arr);
    int gsum=vec[0]%1000000007;
    int si=vec[1];
    int ei=vec[2];
    
    //cout<<gsum<<endl<<si<<endl<<ei<<endl;

    long long lsum=gsum;
    for(int i=ei+1;i<n;i++)
    {
        lsum+=arr[i]%1000000007;
    }
    long long rsum=gsum;
    for(int i=si-1;i>=0;i--)
    {
        rsum+=arr[i]%1000000007;
    }
   // cout<<"lsum="<<lsum<<"  rsum="<<rsum;
    long long msum=array_sum*(k-2)%1000000007;
    long long ans3=(lsum+msum+rsum)%1000000007;
   // cout<<"ans3="<<ans3;
    long long  myans=max(ans2,ans3);

    return myans;

}

int main()
{
    return 0;
}