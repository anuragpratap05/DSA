#include <bits/stdc++.h>
using namespace std;

int friendsPairingHelper(string str, string psf)
{
    if (str.size() == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;
    char ch = str[0];
    cnt += friendsPairingHelper(str.substr(1), psf + ch);
    for (int i = 1; i < str.size(); i++)
    {
        string ans = "";
        ans += ch;
        ans += str[i];
        string before = str.substr(1, i - 1);

        string after = str.substr(i + 1);
        string ros = before + after;
        cnt += friendsPairingHelper(ros, psf + "(" + ans + ")");
    }
    return cnt;
}
int friendsPairing(string str)
{
    return friendsPairingHelper(str, "");
}

int pairingHelper(int n,vector<bool>& vis,string psf,int taken)
{
    if(taken==n)
    {
        cout << psf << endl;
        return 1;
    }

    int leftOutFriend = -1;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            leftOutFriend = i;
            break;
        }
    }
    vis[leftOutFriend] = true;
    int cnt = 0;
    cnt += pairingHelper(n, vis,psf+to_string(leftOutFriend),taken+1);

    for (int readyToPair = leftOutFriend + 1; readyToPair <= n;readyToPair++)
    {
        if(!vis[readyToPair])
        {
            vis[readyToPair] = true;
            cnt += pairingHelper(n, vis, psf +"("+ to_string(leftOutFriend) + to_string(readyToPair)+")",taken+2);
            vis[readyToPair] = false;
        }
    }
    vis[leftOutFriend] = false;
    return cnt;
}

int pairing(int n)
{
    vector<bool> vis(n + 1, false);
    return pairingHelper(n, vis,"", 0);
}

int main()
{
    string s = "ABCD";
    // char ch = s[0];
    // for (int i = 1; i < s.size(); i++)
    // {
    //     string ans = "";
    //     ans += ch;
    //     ans += s[i];
    //     string before = s.substr(1, i - 1);

    //     string after = s.substr(i + 1);
    //     string ros = before + after;
    //     cout << "ans= " << ans << "  ->  "
    //          << "ros= " << ros << endl;
    // }
    // cout << ans;


    // cout << friendsPairing(s);
    cout << pairing(4);
    return 0;
}