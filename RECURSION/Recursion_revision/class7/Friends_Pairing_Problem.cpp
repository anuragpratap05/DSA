#include <bits/stdc++.h>
using namespace std;

int countFriendsPairingsHelp(int n, vector<bool> &vis, string psf, int baseMark)
{
    if (baseMark == n)
    {
        // cout << psf << endl;
        return 1;
    }

    int cnt = 0;
    int firstEle = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (firstEle == -1)
            {
                firstEle = i;

                vis[i] = true;
                cnt += countFriendsPairingsHelp(n, vis, psf + to_string(i) + " ", baseMark + 1);
                vis[i] = false;
            }
            else
            {
                vis[i] = true;
                vis[firstEle] = true;
                cnt += countFriendsPairingsHelp(n, vis, psf + to_string(firstEle) + to_string(i) + " ", baseMark + 2);
                vis[firstEle] = false;

                vis[i] = false;
            }
        }
    }
    return cnt;
}
int countFriendsPairings(int n)
{
    vector<bool> vis(n + 1, false);
    return countFriendsPairingsHelp(n, vis, "", 0);
}

int countFriendsPairingsHelper(string str, string psf)
{
    if (str.size() == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i == 0)
        {
            cnt += countFriendsPairingsHelper(str.substr(1), psf + str[0] + " ");
        }
        else
        {
            string ques = str.substr(1, i - 1) + str.substr(i + 1);
            cnt += countFriendsPairingsHelper(ques, psf + str[0] + str[i] + " ");
        }
    }
    return cnt;
}
int countFriendsPairings(string str)
{
    return countFriendsPairingsHelper(str, "");
}

int main()
{
    // cout << countFriendsPairings("ABCD");
    // int n;
    // cin >> n;
    cout << countFriendsPairings(14);
    // 997313824 for n=18
    return 0;
}