#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
    {
        return true;
    }
    return false;
}

int maxVowels(string s, int k)
{
    int n = s.size();
    if (n < k)
    {
        return 0;
    }
    int prev = 0;
    int curr = 0;
    int vowelCnt = 0;
    int ans = 0;
    while (curr < n)
    {
        char ch = s[curr];
        if (isVowel(ch))
        {
            vowelCnt++;
        }
        while ((curr - prev) + 1 > k)
        {
            char prevCh = s[prev];
            if (isVowel(prevCh))
            {
                vowelCnt--;
            }
            prev++;
        }
        if (vowelCnt > ans)
        {
            ans = vowelCnt;
            if (ans == k)
            {
                return ans;
            }
        }
        curr++;
    }
    return ans;
}

int main()
{
    return 0;
}