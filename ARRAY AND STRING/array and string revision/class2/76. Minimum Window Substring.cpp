#include<bits/stdc++.h>
using namespace std;


string minWindow(string s, string t)
    {
        int n=s.length();
    int count=t.length();
    int len=1e8;
    int si=0,ei=0;
    
    vector<int>freq(128,0);
    for(int i=0;i<count;i++)
    {
        char ch=t[i];
        freq[ch]++;
    }
    int i=0;int p=0;
    while(i<n)
    {
        char ch=s[i];
        
        if(freq[ch]>0)
        {
            count--;
        }
        freq[ch]--;
        
        
        while(count==0)
        {
            
            char nch=s[p];
            
            if(freq[nch]==0)
            {
                if(i-p<len)
                {
                    len=i-p;
                    si=p;
                    ei=i;
                }
                
                count++;

            }
            //freq[p]++;
            freq[nch]++;
            p++;
        }
        
        i++;
    }
        if(len==1e8)
        {
            return "";
        }
         cout<<si<<" "<<ei;
        string ans=s.substr(si,len+1);
        return ans;
    
    // return "";
    
    }


int main()
{
    return 0;
}