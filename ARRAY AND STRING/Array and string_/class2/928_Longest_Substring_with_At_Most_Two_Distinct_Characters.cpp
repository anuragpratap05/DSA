#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringTwoDistinct(string &s)
{
    int n=s.length();

    int ei=0;
    int si=0;
    vector<int> freq(128,0);
    int c=0;
    int len=0;
    while(ei<n)
    {
        if(freq[s[ei]]==0)
        {
            c++;
        }
        freq[s[ei]]++;
        ei++;
        while(c>2)
        {
            freq[s[si]]--;
            if(freq[s[si]]==0)
            {
                c--;
            }
            
            si++;
        }
        len=max(len,ei-si);
    }     
    return len;   
}

int main()
{
    return 0;
}