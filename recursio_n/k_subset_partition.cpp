#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<int> >& v,int n,int k,int idx,int nos)
{
    if(idx>n)
    {
        if(nos==k)
        {
            for(auto ele:v)
            {
                for(auto x:ele)
                {
                    cout<<x;
                }

                cout<<"  ";
            }
            cout<<endl;
            
        }
        return;
    }

    for(int i=0;i<k;i++)
    {
        if(v[i].size()>0)
        {
            v[i].push_back(idx);
            help(v,n,k,idx+1,nos);
            v[i].pop_back();
        }
        else
        {
            v[i].push_back(idx);
            help(v,n,k,idx+1,nos+1);
            v[i].pop_back();
            break;
        }
    }
}

int main()
{
    int n,k;
    n=4,k=3;

    //cin>>n>>k;
    vector<vector<int> > v;

    for (int i = 0; i < k; i++)
	{
		vector<int> x;
		v.push_back(x);
	}

    help(v,n,k,1,0);
}