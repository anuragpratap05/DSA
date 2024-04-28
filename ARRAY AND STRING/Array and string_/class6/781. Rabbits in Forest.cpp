#include<bits/stdc++.h>
using namespace std;


int numRabbits(vector<int>& answers)
{
    //vector<int> vis(1001,0);
    map<int,int> m;
    int ans=0;
    for(int i=0;i<answers.size();i++)
    {
        int ele=answers[i];
        if(ele==0)
        {
            ans++;
        }
        else{
            m[ele]++;
        }

    }
    for(auto i:m)
    {
        int a=i.first;
        int b=i.second;

        a=a+1;
        int q=b/a;
        int r=b%a;
        if(q==0)
        {
            ans+=a;
        }
        else{
            if(r==0)
            {
                q=q-1;
                ans+=(a+a*q);
            }
            else
            {
               ans+=(a+a*q); 
            }
        }
    }
    return ans;

}

//method2
int numRabbits(vector<int>& answers)
{
    int ans=0;
    vector<int> mapp(1001,0);
    for(int ele:answers)
    {
        if(mapp[ele]==0)
        {
            ans+=(ele+1);
        }
        mapp[ele]++;
        if(mapp[ele]==ele+1)
        {
            mapp[ele]=0;
        }
    }
    return ans;
}

int main()
{
    return 0;
}