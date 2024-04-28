#include<bits/stdc++.h>
using namespace std;


int maxVowels(string s, int k)
{
    int n=s.length();
    int si=0;
    int ei=0;
    vector<bool> freq(26,false);
    freq[0]=true;
    freq['e'-'a']=true;
    freq['i'-'a']=true;
    freq['o'-'a']=true;
    freq['u'-'a']=true;
    int len=0;
    int v=0;


    
    while(ei<n)
    {
        char ch=s[ei];
        //cout<<ch<<endl;
        if(freq[ch-'a'])
        {
            //cout<<"aya"<<endl;
            v++;
        }
        ei++;
        if(ei-si==k)
        {
            
            if(v>len)
            {
                len=v;
            }
            if(freq[s[si]-'a'])
            {
                //cout<<"si="<<si;
                v--;
            }
            si++;
        }
    }
    return len;        
}

int main()
{
    //char ch='z';
    //cout<<'z'-'a';
    
    cout<<maxVowels("abciiidef",3);
    return 0;
}