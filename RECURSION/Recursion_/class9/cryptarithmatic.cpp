#include <bits/stdc++.h>
using namespace std;

// H.W. see time comlexity last hour in last class of recursion

bool sum_help(map<char, int> charIntMap, string s1, string s2, string s3)
{
    int num1 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        int val = charIntMap[s1[i]];
        num1 = (num1 * 10) + val;
    }

    int num2 = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        int val = charIntMap[s2[i]];
        num2 = (num2 * 10) + val;
    }

    int num3 = 0;
    for (int i = 0; i < s3.length(); i++)
    {
        int val = charIntMap[s3[i]];
        num3 = (num3 * 10) + val;
    }

    if (num1 + num2 == num3)
    {
        return true;
    }
    return false;
}

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

void solution_help(string unique, int idx, map<char, int> &charIntMap, vector<bool> &vis, string s1, string s2, string s3)
{
    if (idx == unique.length())
    {
        int n1 = conv(s1, charIntMap);
        int n2 = conv(s2, charIntMap);
        int n3 = conv(s3, charIntMap);
        if (n1+n2==n3)
        {
            for (pair<char, int> p : charIntMap)
            {
                cout << p.first << "-" << p.second << " ";
            }
            cout << endl;
        }

        return;
    }
    char ch=unique[idx];
    for (int i = 0; i <= 9; i++)
    {
        if (!vis[i])
        {
            // if((s1[0]==ch or s2[0]==ch or s3[0]==ch) and i==0)
            // {
            //     continue;
            // }
            vis[i] = true;
            charIntMap[ch] = i;
            solution_help(unique, idx + 1, charIntMap, vis, s1, s2, s3);
            vis[i] = false;
        }
    }
}

void solution(string s1, string s2, string s3)
{
    // string str=s1+s2+s3;
    // vector<bool>freq(26,false);
    // for(char ch:str)
    // {
    //     freq[ch-'a']=true; 
    // }
    // //cout<<str<<endl;

    // string unique = "";
    // for(int i=0;i<26;i++)
    // {
    //     if(freq[i])
    //     {
    //         unique+=(i+'a');
    //     }
    // }
    // //cout<<unique;
    // //sort(unique.begin(), unique.end());
    // vector<bool> vis(10, false);
    // map<char, int> charIntMap;

    map<char, int> m;

    string unique = "";

    for (int i = 0; i < s1.length(); i++)
    {
        if (!m[s1[i]])
        {
            m[s1[i]] = -1;
            unique += s1[i];
        }
    }

    for (int i = 0; i < s2.length(); i++)
    {
        if (!m[s2[i]])
        {
            m[s2[i]] = -1;
            unique += s2[i];
        }
    }

    for (int i = 0; i < s3.length(); i++)
    {
        if (!m[s3[i]])
        {
            m[s3[i]] = -1;
            unique += s3[i];
        }
    }
    vector<bool> vis(10, false);

    solution_help(unique, 0, m, vis, s1, s2, s3);
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    solution(s1, s2, s3);
    return 0;
}