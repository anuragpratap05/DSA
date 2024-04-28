#include <bits/stdc++.h>
using namespace std;

vector<string> keyPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinationsHelper(string digits)
{
    if (digits.size() == 0)
    {
        return {""};
    }
    int keyNumber = digits[0] - '0';
    vector<string> recAns = letterCombinationsHelper(digits.substr(1));
    vector<string> myAns;
    for (char ch : keyPad[keyNumber])
    {
        for (string str : recAns)
        {
            myAns.push_back(ch + str);
        }
    }
    return myAns;
}

void letterCombinationsHelperVoidType(string digits, vector<string> &ans, string psf)
{
    if (digits.size() == 0)
    {
        ans.push_back(psf);
        return;
    }
    int keyNumber = digits[0] - '0';

    for (char ch : keyPad[keyNumber])
    {
        letterCombinationsHelperVoidType(digits.substr(1), ans, psf + ch);
    }
}

vector<string>
letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return {};
    }
    vector<string> ans;
    letterCombinationsHelperVoidType(digits, ans, "");
    return ans;
    // return letterCombinationsHelper(digits);
}

int main()
{
    char ch = '2';
    int a = ch - '0';
    cout << a << endl;
    cout << a + 1;

    return 0;
}