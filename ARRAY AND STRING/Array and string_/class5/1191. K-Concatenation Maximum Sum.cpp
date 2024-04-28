#include<bits/stdc++.h>
using namespace std;

int kadan(vector<int>& arr, int k)
{
    long csum,gsum;
    csum=gsum=0;
    while(k--)
        {
            for(int i=0;i<arr.size();i++)
            {
                int ele=arr[i];
                csum+=ele;
                
                if(csum>gsum)
                {
                    gsum=csum;
                }
                if(csum<=0)
                {
                    csum=0;
                }
                
            }
        }
        return gsum;
}
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long psum=0,sum=0;
    for(int i=1;i<=3;i++)
    {
        psum=sum;
        sum=kadan(arr,i);
        cout<<sum<<endl;
        if(k==i)
        {
            
            return sum%1000000007;
        }

    }  
        // cout<<"sum="<<sum<<endl;
        // cout<<"psum="<<psum<<endl;
    return (psum+(k-2)*(sum-psum))%1000000007;
    }

// method2 by maintaining prefix and suffix sum
int kConcatenationMaxSum2(vector<int>& arr, int k)
{
    long one=kadan(arr,1);
    if(k==1)
    {
        return one%1000000007;
    }
    long psum=0,ssum=0,mpsum=0,mssum=0,asum=0;
    for(int i=0;i<arr.size();i++)
    {
        psum+=arr[i];
        asum+=arr[i];
        if(psum>mpsum)
        {
            mpsum=psum;
        }
    }  
    for(int i=arr.size()-1;i>=0;i--)
    {
        ssum+=arr[i];
        if(ssum>mssum)
        {
            mssum=ssum;
        }
    }  
    if(asum<0)
    {
        asum=0;
    }  
    long ans=max(mpsum+mssum,(mpsum+mssum)+(k-2)*asum);
    long final=max(ans,one);


    return  final%1000000007;

}

int main()
{
    return 0;
}