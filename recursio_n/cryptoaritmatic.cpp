#include<bits/stdc++.h>
using namespace std;

int conv(string s,map<char,int>& m)
{
   //string str="";
   int res=0;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        int x=m[ch];
        res=res*10+x;
    }
    
    return res;
}


void help(map<char,int>& m,vector<bool>& vis,string s1,string s2,string s3,string unq,int idx)
{
    if(idx==unq.length())
    {
        int num1=conv(s1,m);
        int num2=conv(s2,m);
        int num3=conv(s3,m);
        if(num1+num2==num3)
        {
            for(auto ele:m)
            {
                cout<<ele.first<<"-"<<ele.second<<"  ";
            }
            cout<<endl;
        }
        return;
    }

    char ch=unq[idx];
    for(int i=0;i<=9;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            m[ch]=i;
            help(m,vis,s1,s2,s3,unq,idx+1);
            vis[i]=false;
            m[ch]=-1;
        }
    }
    return;
}

int main()
{
    string s1,s2,s3;
    //cin>>s1>>s2>>s3;

    s1="team";
    s2="pep";
    s3="toppr";

    map<char,int> m;

    string unq="";

    for(int i=0;i<s1.length();i++)
    {
        if(!m[s1[i]])
        {
            m[s1[i]]=-1;
            unq+=s1[i];
        }
    }

     for(int i=0;i<s2.length();i++)
    {
        if(!m[s2[i]])
        {
            m[s2[i]]=-1;
            unq+=s2[i];
        }
    }

    for(int i=0;i<s3.length();i++)
    {
        if(!m[s3[i]])
        {
            m[s3[i]]=-1;
            unq+=s3[i];
        }
    }
    vector<bool> vis(10,false);
    help(m,vis,s1,s2,s3,unq,0);
    //cout<<unq;
}