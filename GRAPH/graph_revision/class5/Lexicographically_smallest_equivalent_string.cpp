#include<bits/stdc++.h>
using namespace std;
vector<int> par(26);
int find(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    par[i]=find(par[i]);
    return par[i];
}
string smallestString(string s, string t, string str)
{
	for(int i=0;i<26;i++)
    {
        par[i]=i;
    }
    for(int i=0;i<s.length();i++)
    {
        char ch1=s[i];
        char ch2=t[i];
       // cout<<ch1<<" "<<ch1-97<<" and "<<ch2<<" "<<ch2-97<<endl;

        int p1=find(ch1-97);
        int p2=find(ch2-97);
        if(p1!=p2)
        {
            if(p1<p2)
            {
                par[p2]=p1;
            }
            else
            {
                par[p1]=p2;
            }
        }
        
    }
    string myans="";
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        int p=find(ch-97);
        char s1=p+'a';
        myans+=s1;
    }
    return myans;
}


int main()
{
    cout<<smallestString("coding","ninjaa","nijng");
    return 0;
}