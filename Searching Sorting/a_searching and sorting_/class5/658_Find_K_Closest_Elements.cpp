#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
void closek(vector<int>& arr,int p1,int p2,int x,int k,vector<int>& ans)
{
    //vector<int> ans;
    int n=arr.size();
    while(k--)
    {
        int dr= (p1<=n-1?  arr[p1]-x:INT_MAX);
        int dl=  (p2>=0?x-arr[p2]:INT_MAX);

        if(dr<dl)
        {
            ans.push_back(arr[p1]);
            p1++;
        }
        else 
        {
           ans.push_back(arr[p2]);
            p2--; 
        }


    }
    //return ans;



}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(n==k)
        {
            return arr;
        }
   int idx= last_index_if_ele_ispressent(arr,x);
    vector<int > ans;
//    if(idx==0)
//    {
       
//        for(int i=0;i<k;i++)
//        {
//            ans.push_back(arr[i]);
//        }
//        return ans;
//    }
//    else if(idx>n-1)
//    {
       
//        for(int i=n-k;i<n;i++)
//        {
//          ans.push_back(arr[i]);  
//        }
//        return ans;
//    }
  // else{
        if(idx>n-1)
        {
            idx=n-1;
        }
       if(arr[idx]==x)
       {
           ans.push_back(x);
           closek(arr,idx+1,idx-1,x,k-1,ans);
           sort(ans.begin(),ans.end());
           return ans;
       }
       else{
           closek(arr,idx,idx-1,x,k,ans);
           sort(ans.begin(),ans.end());
           return ans;
       }
        return ans;

   }
        
    
};

// better soln:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
    int si=0;
    int ei=(n)-k;

    while(si<ei)
    {
        int mid=(si+ei)/2;
        int next=(mid+(k));
        if(x-arr[mid]>arr[next]-x)
        {
            si=mid+1;
        }
        else{
            
            ei=mid;
        }
    }  
        cout<<si;

    return {arr.begin()+si,arr.begin()+(si+k)};
    }

int main()
{
    // vector<int>arr = {1,2,3,4,5};
    // int k = 4,  x = 3;
    // vector<int> ans=findClosestElements(arr,k,x);
    // sort(ans.begin(),ans.end());

    // for(int ele:ans)
    // {
    //     cout<<ele<<" ";
    // }


    return 0;
}