#include<bits/stdc++.h>
using namespace std;
//vector<string> mapping = {".","abc" ,"def" ,"ghi", "jkl" ,"mno", "pqrs" ,"tu","vwx" ,"yz"};
vector<string> mapping = {"","","abc" ,"def" ,"ghi", "jkl" ,"mno", "pqrs" ,"tuv","wxyz"};

vector<string> getKPC(string s,int idx)
{
    if(idx==s.size())
    {
        vector<string>base={""};
        return base;

    }

    vector<string>sa=getKPC(s,idx+1);
    int digit=s[idx]-'0';
    string str=mapping[digit];
    cout<<str<<endl;
    vector<string>myans;
    for(auto ch:str)
    {
        for(auto ele:sa)
        {
            myans.push_back(ch+ele);
        }
    }
    return myans;  
}

int main()
{
    vector<string> ans=getKPC("78",0);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    return 0;
}