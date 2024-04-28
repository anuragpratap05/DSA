#include<bits/stdc++.h>
using namespace std;

map<int,int> m;


int twosumc(vector<int>& nums3, vector<int>& nums4,int tar)
{
    int n=nums3.size();
    sort(nums3.begin(),nums3.end());
    sort(nums4.begin(),nums4.end());
    bool flag=false;
    int c=0;
    vector<int> vec1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sum=nums3[i]+nums4[j];
            if(sum>tar)
            {
                break;
            }
            if(sum==tar)
            {
                c++;
            }
            
        }
        // if(flag)
        // {
        //     break;
        // }
    }
    return c;
    
}

// int threesumc(vector<int>& nums2,vector<int>& nums3, vector<int>& nums4,int tar)
// {
//      int c=0;
//     for(int i=0;i<nums2.size();i++)
//     {
//         int ntar=tar-nums2[i];
//         if(m[ntar]!=0)
//         {
//             c+=m[ntar]
//         }
//         //c+=twosumc(nums3,nums4,tar-nums2[i]);
//     }
//     return c;

// }

vector<int> makevec(vector<int>& num1,vector<int>& num2)
{
    int n=num1.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans.push_back(num1[i]+num2[j]);     
        }
        
    }
    return ans;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    vector<int >vec1=makevec(nums1,nums2);
    vector<int >vec2=makevec(nums3,nums4);

    int c=twosumc(vec1,vec2);
    return c;


}

int main()
{
    vect
    return 0;
}