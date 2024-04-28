#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringKDistinct(string &s, int k)
{
    vector<int>vec(128,0);
    int i=0;int p=0;
    int n=s.length();
    int distinct=0;
    int maxi=0;
    while(i<n)
    {
        char ch=s[i];
        if(vec[ch]==0)
        {
            distinct++;
        }
        vec[ch]++;
        while(distinct>k)
        {
            char nch=s[p];
            vec[nch]--;
            if(vec[nch]==0)
            {
                distinct--;
            }
            p++;
        }
        i++;
        maxi=max(maxi,i-p);
    }
    return maxi;
}

int main()
{
    return 0;
}