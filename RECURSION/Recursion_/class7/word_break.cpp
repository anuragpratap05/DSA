#include <bits/stdc++.h>
using namespace std;

int word_brreak(string str, unordered_set<string> &s,string psf)
{
    if (str.size() == 0)
    {
        cout<<psf<<endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        string word = str.substr(0, i);
        
        if (s.find(word) != s.end())
        {
            count += word_brreak(str.substr(i), s,psf+word+" ");
        }
    }
    return count;
}
int main()
{

    int n ;
    cin>>n;
    unordered_set<string> s;
    while(n--)
    {
        string x;
        cin>>x;
        s.insert(x);
    }
    
    
    string str ;
    cin>>str;
    cout << word_brreak(str, s,"");
    return 0;
}