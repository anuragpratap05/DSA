#include <bits/stdc++.h>
using namespace std;

void permu(string str, string psf)
{
    if (str.size() == 0)
    {
        cout << psf << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string ros = str.substr(0, i) + str.substr(i + 1);
        permu(ros, psf + ch);
    }
}

void permuUniqueVisitedHelp(string str, string psf)
{
    if (str.size() == 0)
    {
        cout << psf << endl;
        return;
    }
    vector<bool> vis(26, false);
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (!vis[ch - 'a'])
        {
            vis[ch - 'a'] = true;
            string ros = str.substr(0, i) + str.substr(i + 1);
            permuUniqueVisitedHelp(ros, psf + ch);
        }
    }
}

void permuUniqueHelp(string str, string psf)
{
    if (str.size() == 0)
    {
        cout << psf << endl;
        return;
    }

    char prev = '@';
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch != prev)
        {
            prev = ch;
            string ros = str.substr(0, i) + str.substr(i + 1);
            permuUniqueHelp(ros, ch + psf);
        }
    }
}

void permuUniqueVisited(string str)
{
    sort(str.begin(), str.end());
    // permuUniqueVisitedHelp(str, "");
    permuUniqueHelp(str, "");
}

int main()
{
    // permu("123", "");
    permuUniqueVisited("abaa");
    return 0;
}