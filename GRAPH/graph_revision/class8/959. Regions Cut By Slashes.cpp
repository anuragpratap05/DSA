#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>size;
int find(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    par[i]=find(par[i]);
    return par[i];
}
void unite(int p1,int p2)
{
    par[p1]=p2;
}
int regionsBySlashes(vector<string>& grid)
{
    int n=grid.size();
    int my_n=n+1;
    int m=n+1;
    par.resize(my_n*my_n);
    size.resize(my_n*my_n,1);
    for(int i=0;i<(my_n * my_n);i++)
    {
        par[i]=i;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0 or i==n or j==n)
            {
                if(i==0 and j==0)
                {
                    continue;
                }
                int v=i*m+j;
                int u;
                if(j==0)
                {
                    u=(i-1)*m+j;

                }
                else if(i==0)
                {
                    u=i*m+(j-1);
                }
                else if(i==n)
                {
                    u=i*m+(j-1);
                }
                else{
                    u=(i-1)*m+j;
                }

                int p1=find(u);
                int p2=find(v);
                if(p1!=p2)
                {
                    unite(p1,p2);
                }
            }
        }
    } 
    int c=0;
    for(int i=0;i<n;i++)
    {
        string s=grid[i];
        for(int j=0;j<n;j++)
        {
            char ch =s[j];
            if(ch=='/')
            {
                int u=i*m+(j+1);
                int v=(i+1)*m+j;
                int p1=find(u);
                int p2=find(v);
                if(p1==p2)
                {
                  c++;  
                }
                unite(p1,p2);
            }
            else if(ch =='\\')
            {
                int u=i*m+j;
                int v=(i+1)*m+(j+1);
                int p1=find(u);
                int p2=find(v);
                if(p1==p2)
                {
                  c++;  
                }
                unite(p1,p2);
            }
        }
    }   
    return c;    
}

int main()
{
    return 0;
}