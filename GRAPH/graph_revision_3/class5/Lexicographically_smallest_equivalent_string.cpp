#include <bits/stdc++.h>
using namespace std;
vector<int> par(26);

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }
    return par[i] = find(par[i]);
    // return par[i];
}

void unite(int p1, int p2)
{
    if (p1 < p2)
    {
        par[p2] = p1;
    }
    else
    {
        par[p1] = p2;
    }
}

string smallestString(string s, string t, string str)
{
    for (int i = 0; i < 26; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        int v = t[i] - 'a';

        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2)
        {
            unite(p1, p2);
        }
    }
    string ans = "";
    for (char ch : str)
    {
        int x = ch - 'a';
        int p = find(x);
        ans += p + 'a';
    }
    return ans;
}

int main()
{
    char ch = 'a' + 0;
    cout << ch;
    return 0;
}