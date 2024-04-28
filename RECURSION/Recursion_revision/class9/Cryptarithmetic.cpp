#include <bits/stdc++.h>
using namespace std;
int conv(string s, map<char, int> &m)
{
    // string str="";
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int x = m[ch];
        res = res * 10 + x;
    }

    return res;
}

bool isSumEqual(map<char, int> &mp, string s1, string s2, string s3)
{
    string str1 = "";
    for (char ch : s1)
    {
        str1 += mp[ch] + '0';
    }

    string str2 = "";
    for (char ch : s2)
    {
        str2 += mp[ch] + '0';
    }

    string str3 = "";
    for (char ch : s3)
    {
        str3 += mp[ch] + '0';
    }
    // cout << str1 << " " << str2 << " " << str3 << endl;
    int num1 = stoi(str1);
    int num2 = stoi(str2);
    int num3 = stoi(str3);
    if (num1 + num2 == num3)
    {

        return true;
    }
    return false;
}

int CryptarithmeticHelp(string str, vector<bool> &used, int idx, map<char, int> &mp, string s1, string s2, string s3)
{
    if (idx == str.size())
    {
        int num1 = conv(s1, mp);
        int num2 = conv(s2, mp);
        int num3 = conv(s3, mp);
        if (num1 + num2 == num3)
        {
            for (auto ele : mp)
            {
                cout << ele.first << "-" << ele.second << " ";
            }
            cout << endl;
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    char ch = str[idx];
    for (int i = 0; i <= 9; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            mp[ch] = i;
            cnt += CryptarithmeticHelp(str, used, idx + 1, mp, s1, s2, s3);
            used[i] = false;
            mp[ch] = -1;
        }
    }
    return cnt;
}
void Cryptarithmetic(string s1, string s2, string s3)
{
    vector<bool> vis(26, false);
    string str = "";
    for (char ch : s1)
    {
        if (!vis[ch - 'a'])
        {
            vis[ch - 'a'] = true;
            str += ch;
        }
    }

    for (char ch : s2)
    {
        if (!vis[ch - 'a'])
        {
            vis[ch - 'a'] = true;
            str += ch;
        }
    }

    for (char ch : s3)
    {
        if (!vis[ch - 'a'])
        {
            vis[ch - 'a'] = true;
            str += ch;
        }
    }
    map<char, int> mp;
    vector<bool> used(10, false);
    sort(str.begin(), str.end());
    // cout << str << endl;
    cout << CryptarithmeticHelp(str, used, 0, mp, s1, s2, s3);
}

int main()
{
    // string s1, s2, s3;
    // cin >> s1 >> s2 >> s3;

    Cryptarithmetic("send", "more", "money");
    // Cryptarithmetic(s1, s2, s3);
    return 0;
}