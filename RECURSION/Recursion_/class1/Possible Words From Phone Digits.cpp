#include<bits/stdc++.h>
using namespace std;
vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> getKPC(vector<int>& s, int idx)
{
    if (idx == s.size())
    {
        vector<string> base = {""};
        return base;
    }

    vector<string> sa = getKPC(s, idx + 1);
    int digit = s[idx] ;
    string str = mapping[digit];
    cout << str << endl;
    vector<string> myans;
    for (auto ch : str)
    {
        for (auto ele : sa)
        {
            myans.push_back(ch + ele);
        }
    }
    return myans;
}

vector<string> possibleWords(int a[], int N)
{
    vector<int>vec;
    for(int i=0;i<N;i++)
    {
        vec.push_back(a[i]);
    }
    return getKPC(vec,0);
}

int main()
{
    return 0;
}