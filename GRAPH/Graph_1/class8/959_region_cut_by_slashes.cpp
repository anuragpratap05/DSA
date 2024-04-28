#include<bits/stdc++.h>
using namespace std;
vector<int> par;
      int find(int u)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u]);
    return par[u];
}
int Union(int p1,int p2)
{
    if(p1!=p2)
    {
        par[p1]= min(p1,p2);
        par[p2]=min(p1,p2);
        return 0;
    }
    return 1;
    
}
int regionsBySlashes(vector<string>& grid)
{
    int n=grid.size();
    int N=n+1;
     par.resize(N*N);

    for(int i=0;i<N*N;i++)
    {
        if(i/N==0 or i%N==0 or i/N==N-1 or i%N==N-1)
        {
            par[i]=0;
        }
        else
        {
            par[i]=i;
        }
    }
    int regions=1;
    for(int r=0;r<n;r++)
    {
        string s=grid[r];
        for(int c=0;c<s.length();c++)
        {
            if(s[c]=='/')
            {
                regions+=Union(find(r*N+c+1),find((r+1)*N+c));
            }
            else if(s[c]=='\\')
            {
                regions+=Union(find(r*N+c),find((r+1)*N+c+1));
            }
        }
    }   
    return regions;     
}


int main()
{
    return 0;
}