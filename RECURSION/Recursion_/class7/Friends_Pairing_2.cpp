#include <bits/stdc++.h>
using namespace std;

int friends_help(int n, string psf, int idx, vector<bool> &vis)
{
    if (idx > n)
    {
        cout << psf << endl;
        return 1;
    }
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            count += friends_help(n, psf + to_string(i) + " ", i + 1, vis);
            vis[i] = false;
        }
    }
    

    for (int j = 1; j <= n; j++)
    {
        if (!vis[j] and j!=n )
        {
            vis[j] = true;
            count += friends_help(n, psf + to_string(j), j+1, vis);
            vis[j] = false;
        }
        
    }
    

    return count;
}

int main()
{
    int n = 4;
    vector<bool> vis(n + 1, false);
    friends_help(n, "", 1, vis);
    return 0;
}