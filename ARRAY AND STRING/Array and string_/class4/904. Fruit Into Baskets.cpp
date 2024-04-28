#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> freq(100001,0);
        int si,ei,len,c;
        si=ei=len=c=0;
        
        int n=fruits.size();
        while(ei<n)
        {
            if(freq[fruits[ei]]==0)
            {
                c++;
            }
            freq[fruits[ei]]++;
            ei++;
            
            while(c>2)
            {
                freq[fruits[si]]--;
                if(freq[fruits[si]]==0)
                {
                    c--;
                }
                si++;
            }
            len=max(len,ei-si);
            
            
        }
        return len;
    }
    
};

int main()
{
    return 0;
}