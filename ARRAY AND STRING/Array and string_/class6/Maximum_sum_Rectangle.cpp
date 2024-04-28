#include<bits/stdc++.h>
using namespace std;

vector<int> kadanes(vector<int> arr)
{
    int n=arr.size();
    int csum=0;
    int gsum=0;
    int si=0,ei=0;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        csum+=ele;
        if(csum<=0)
        {
            si=i+1;

            csum=0;
        }
        if(csum>gsum)
        {
            gsum=csum;
            ei=i;

        }


    }
    return {gsum,si,ei};
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    vector<int> vec;
    int maxi=0;

    for(int r=0;r<R;r++)
    {
        cout<<endl;
        vec.clear();
        vec.resize(C,0);
        for(int i=r;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                vec[j]+=M[i][j];
            }
            vector<int> sum=kadanes(vec);
            if(sum[0]>maxi)
            {
                maxi=sum[0];
                int sr=r;
                int sc=sum[1];
                int er=i;
                int ec=sum[2];
                // for printing maximum matrix
                cout<<"("<<sr<<","<<sc<<")  ("<<er<<","<<ec<<")"<<endl;
            }
        }
        
    }
    return maxi;
}

int main()
{
    int R=4;
    int C=5;
    vector<vector<int>>M={{1,2,-1,-4,-20},
    {-8,-3,4,2,1},
    {3,8,10,1,3},
    {-4,-1,1,7,-6}};

    cout<<maximumSumRectangle(R,C,M);
    return 0;
}