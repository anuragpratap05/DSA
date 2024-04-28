#include<bits/stdc++.h>
using namespace std;

vector<int>par;
int find(int u)
{
    if(par[u]==u)
    {
        return u;
    }
    par[u]=find(par[u]);
    return par[u];
}
bool issimilar(string s1,string s2)
{
    int n=s1.length();
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            c++;
        }
        if(c>2)
        {
            return false;
        }
    }
    return true;
}
int numSimilarGroups(vector<string>& strs)
{       
    int n=strs.size();
    par.resize(n);
    for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    int num=n;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(issimilar(strs[i],strs[j]))
            {
                int p1=find(i);
                int p2=find(j);
                if(p1!=p2)
                {
                    par[p2]=p1;
                    num--;
                }
            }
        }
    }
    return num;
}

int main()
{
    return 0;
}