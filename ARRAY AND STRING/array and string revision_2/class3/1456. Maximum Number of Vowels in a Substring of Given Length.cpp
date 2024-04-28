#include<bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k)
{
    vector<bool> freq(128, false);
    freq['a'] = true;
    freq['e'] = true;
    freq['i'] = true;
    freq['o'] = true;
    freq['u'] = true;
    int maxi = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        char ch = s[i];
        if (freq[ch])
        {
            maxi++;
        }
    }

    int n = s.size();
    int p = 0;
    int temp = maxi;
    cout << temp;
    while (i < n)
    {
        if (freq[s[p]])
        {
            temp--;
        }
        p++;
        if (freq[s[i]])
        {
            temp++;
        }
        i++;
        maxi = max(maxi, temp);
    }
    return maxi;
}

int main()
{
    return 0;
}