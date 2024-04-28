#include<bits/stdc++.h>
using namespace std;
//this is better soln
int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int si=0;
        int ei=0;
        int c=0;
        vector<int> freq(128,0);
        int len=0;
        while(ei<n)
        {
            if(freq[s[ei]]>0)
            {
                c++;
            }
            freq[s[ei]]++;
            ei++;
            while(c!=0)
            {
                if(freq[s[si]]>1)
                {
                    c--;
                }
                freq[s[si]]--;
                si++;
            }
            len=max(len,ei-si);
        }
        return len;
    }


// int lengthOfLongestSubstring(string s)
// {
//     map<char,int> m;
//     int len=0;
//     int maxi=0;
//     for(int i=0;i<s.length();i++)
//     {
//         char ch=s[i];
//        // cout<<i<<endl;
//        cout<<"i="<<i<<endl;
//         if(m[ch]>0)
//         {
            
//             cout<<m[ch]<<" ";
            
//             //cout<<m[ch]<<endl;
//             i=m[ch];
//             i--;
//             maxi=max(maxi,len);
//             len=0;
//             m.clear();
//             cout<<m.size()<<endl;
            
//         }
//         else{
//             cout<<"aya"<<endl;
//             len++;
//             m[ch]=i+1;
//         }
//         maxi=max(maxi,len);
//     }
//     return maxi;
// }

int main()
{
    cout<<lengthOfLongestSubstring("dvdf");
    return 0;
}