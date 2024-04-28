#include<bits/stdc++.h>
using namespace std;


 string minWindow(string s, string t) {
    int n=s.length();
    vector<int> freq(128,0);
    int m=t.length();
    int c=m;
        if(n<m)
        {
            return "";
        }
    for(int i=0;i<m;i++)
    {
        char ch=t[i];
        freq[ch]++;
    }       
    int len=1e9;
    int si=0;
    int gsi=-1;
    int ei=0;
    while(ei<n)
    {
        char ch=s[ei];
        if(freq[ch]>0)
        {
            c--;
        }
        freq[ch]--;
        ei++;
        while(c==0)
        {
            if(freq[s[si]]==0)
            {
                if(ei-si <len)
                {
                    gsi=si;
                    len=ei-si;
                }
                c++;
            }
            freq[s[si]]++;
            si++;
        }
    }
        if(len==1e9)
        {
            return "";
        }
    string ans=s.substr(gsi,len);
        
    return ans;
    }

int main()
{
    return 0;
}