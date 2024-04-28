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

bool equationsPossible(vector<string>& equations)
{
    par.resize(26);
    for(int i=0;i<26;i++)
    {
        par[i]=i;
    }
    int n=equations.size();
    for(int i=0;i<n;i++)
    {
        string s=equations[i];
        if(s[1]=='=')
        {
            int p1=find(s[0]-'a');
            int p2=find(s[3]-'a');
            if(p1!=p2)
            {
                par[p1]=p2;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        string s=equations[i];
        if(s[1]=='!')
        {
            int p1=find(s[0]-'a');
            int p2=find(s[3]-'a');
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