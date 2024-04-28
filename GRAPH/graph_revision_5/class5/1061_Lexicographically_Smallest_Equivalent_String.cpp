#include <bits/stdc++.h>
using namespace std;

vector<int> par;

int find(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find(par[i]);
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

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    for (int i = 0; i < 26; i++)
    {
        par.push_back(i);
    }

    for (int i = 0; i < s1.length(); i++)
    {
        int u = s1[i] - 'a';
        int v = s2[i] - 'a';
        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2)
        {
            unite(p1, p2);
        }
    }
    string ans = "";
    for (char ch : baseStr)
    {
        int p = find(ch - 'a');
        ans += (p + 'a');
    }
    return ans;
}

int main()
{
    // char ch = 'b';
    // int num = ch - 'a';

    // cout << num << endl;

    int num = 1 + 'a';
    char ch = num;
    cout << ch;
    return 0;
}