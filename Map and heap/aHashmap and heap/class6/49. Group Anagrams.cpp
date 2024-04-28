#include<bits/stdc++.h>
using namespace std;




vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<map<char, int>, vector<string>> bigm;

    for(auto& str:strs)
    {
        map<char, int> m;
        for (char ch : str)
        {
            m[ch]++;
        }
        bigm[m].push_back(str);


    }
    vector<vector<string>> ans;

    for(auto p:bigm)
    {
        vector<string> sa;
        for (string str : p.second)
        {
            sa.push_back(str);
        }
        ans.push_back(sa);
    }
    return ans;
}

int main()
{
    return 0;
}