#include<bits/stdc++.h>
using namespace std;

 int lengthOfLongestSubstring(string s) {
        vector<int> vec(128,0);
    int n=s.length();
    int p=0;
    int maxi=0;
    int i=0;
    while(i<n)
    {
        char ch=s[i];
        vec[ch]++;
        if(vec[ch]>1)
        {
            while(vec[ch]>1)
            {
                char nch=s[p];
                vec[nch]--;
                p++;
            }
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