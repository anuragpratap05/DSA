#include <bits/stdc++.h>
using namespace std;

void subseqquencesHelper(string str, int i, vector<string> &ans, string psf)
{
    if (i == str.size())
    {
        ans.push_back(psf);
        return;
    }

    subseqquencesHelper(str, i + 1, ans, psf + str[i]); // aane ki call
    subseqquencesHelper(str, i + 1, ans, psf);          // character ke nhi aane ki call
}

void subseqquences(string str)
{
    // cout << "aya";
    vector<string> ans;
    subseqquencesHelper(str, 0, ans, "");
    for (string str : ans)
    {
        cout << str << ' ';
    }
}

vector<string> subseqquenceReturnType(string str)
{
    if (str.size() == 0)
    {
        return {""};
    }
    char ch = str[0];
    string ros = str.substr(1);

    vector<string> recAns = subseqquenceReturnType(ros);
    vector<string> myAns(recAns);
    for (string str : recAns)
    {
        myAns.push_back(ch + str);
    }
    return myAns;
}

int main()
{

    vector<string> ans = subseqquenceReturnType("abc");
    for (string str : ans)
    {
        cout << str << " ";
    }
    // subseqquences("abc");

    return 0;
}