#include <bits/stdc++.h>
using namespace std;

vector<string> mapp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//top down
vector<string> letterCombinations(string digits, int idx)
{
    if (idx == digits.size())
    {
        return {""};
    }
    char ch = digits[idx];
    int num = ch - '0';
    cout << num << endl;
    string str = mapp[num];

    vector<string> recAns = letterCombinations(digits, idx + 1);
    vector<string> myAns;
    for (char c : str)
    {
        for (string s : recAns)
        {
            myAns.push_back(c + s);
        }
    }
    return myAns;
}

//bottom up
void letterCombinations2(string digits, int idx, string psf,vector<string>& ans)
{
    if (idx == digits.size())
    {
        cout << psf << " ";
        ans.push_back(psf);
        return;
    }
    char ch = digits[idx];
    int num = ch - '0';
    // cout << num << endl;
    string str = mapp[num];
    for (char c : str)
    {
        letterCombinations2(digits, idx + 1, psf + c,ans);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return {};
    }
    vector<string> ans;
    letterCombinations2(digits, 0, "",ans);
    return ans;
}

int main()
{
    letterCombinations("23");
    // for (string s : ans)
    // {
    //     cout << s << " ";
    // }
    return 0;
}