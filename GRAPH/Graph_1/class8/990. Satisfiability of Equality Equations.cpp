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

bool equationsPossible(vector<string>& equations)
{

    int n=equations.size();
    par.resize(26);
    for(int i=0;i<26;i++)
    {
        par[i]=i;
    }

    for(int i=0;i<n;i++)
    {
        string s=equations[i];
        int v1=s[0]-'a';
        char op=s[1];
        int v2=s[3]-'a';
        if(op=='=')
        {
            int p1=find(v1);
            int p2=find(v2);
            if(p1!=p2)
            {
                par[p2]=p1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        string s=equations[i];
        int v1=s[0]-'a';
        char op=s[1];
        int v2=s[3]-'a';
        if(op=='!')
        {
            int p1=find(v1);
            int p2=find(v2);
            if(p1==p2)
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    return 0;
}