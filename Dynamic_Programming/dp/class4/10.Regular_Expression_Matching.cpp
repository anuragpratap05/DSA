#include <bits/stdc++.h>
using namespace std;

string removeStars(string &str)
{
    if (str.size() == 0)
        return "";
    string ans = "";
    ans += str[0];
    int i = 1;
    while (i < str.size())
    {
        while (ans[ans.size() - 1] == '*' and str[i] == '*')
            i++;
        if (i < str.size())
            ans += str[i];
        i++;
    }
    return ans;
}

bool isMatch(string &s, string &p, int i1, int i2)
{
    if (i1 == s.size() or i2 == p.size())
    {
        if (i1 == s.size() and i2 == p.size())
            return true;
        else if ((i2 == p.size() - 1 or i2 == p.size() - 2) and p[p.size() - 1] == '*')
            return true;
        return false;
    }

    char ch1 = s[i1];
    char ch2 = p[i2];

    if (ch1 == ch2 or ch2 == '.')
    {
        bool res = false;
        res = res || isMatch(s, p, i1 + 1, i2 + 1);
        if (i2 + 1 < p.size() and p[i2 + 1] == '*')
            res = res || isMatch(s, p, i1, i2 + 2);
        return res;
    }
    else if (ch2 == '*')
    {
        bool res = false;
        res = res || isMatch(s, p, i1, i2 + 1);
        if (i2 - 1 >= 0 and (p[i2 - 1] == ch1 or p[i2 - 1] == '.'))
            res = res || isMatch(s, p, i1 + 1, i2);
        return res;
    }
    else
    {
        if (i2 + 1 < p.size() and p[i2 + 1] == '*')
            return isMatch(s, p, i1, i2 + 2);
        else
            return false;
    }
}
bool isMatch(string s, string p)
{
    p = removeStars(p);
    return isMatch(s, p, 0, 0);
}

int main()
{
    string s = "bbbba", p = ".*a*a";
    if (isMatch(s, p))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    return 0;
}