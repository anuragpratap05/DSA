#include<bits/stdc++.h>
using namespace std;


int maxVowels(string s, int k)
{
    
    int v=0;
    int n=s.length();
    int i=0;
    for(;i<k;i++)
    {
        if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
        {
            v++;
        }
    }
    int p=0;
    int len=v;
    if(len==k)
    {
        return len;
    }
    while(i<n)
    {
        if(s[p]=='a' or s[p]=='e' or s[p]=='i' or s[p]=='o' or s[p]=='u')
        {
            v--;
        }
        if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
        {
            v++;
            if(v>len)
            {
                len=v;
            }
            if(len==k)
            {
                return len;
            }
        }
        p++;
        i++;
    }
    return len;

}

int main()
{
    cout<<maxVowels("aeiou",2);
    return 0;
}
