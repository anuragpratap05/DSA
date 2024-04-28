#include <bits/stdc++.h>
using namespace std;

vector<string> subSeq(string str, int i)
{
    if (i == str.size())
    {
        return {""};
    }

    vector<string> recAns = subSeq(str, i + 1);
    vector<string> myAns;
    for (string s : recAns)
    {
        myAns.push_back(s);
        myAns.push_back(str[i] + s);
    }
    return myAns;
}

void subSeq(string str, int i, string psf)
{
    if (i == str.size())
    {
        cout << psf << " ";
    }

    subSeq(str, i + 1, psf);
    subSeq(str, i + 1, str[i] + psf);
}

int main()
{
    vector<string> ans = subSeq("abc", 0);
    for (string str : ans)
    {
        cout << str << " ";
    }
    return 0;
}