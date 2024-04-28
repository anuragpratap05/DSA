#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;
// vector<vector<int>> dir = {{0, 1}, {1, 0}};

void unite(int p1, int p2)
{
    if (size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
}

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }

    par[i] = find(par[i]);

    return par[i];
}
bool is_similar(string s1, string s2)
{
    int n = s1.length();
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if(s1[i]!=s2[i])
        {
            c++;
            if(c>2)
            {
                return false;
            }
        }
    }
    return true;
}


int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    int gps = n;

    par.resize(n);
    size.resize(n, 1);

    for (int i = 0; i < n;i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1; j< n;j++)
        {
            if(is_similar(strs[i],strs[j]))
            {
                int p1 = find(i);
                int p2 = find(j);

                if(p1!=p2)
                {
                    unite(p1, p2);
                    gps--;
                }
            }
        }
    }
    return gps;
}

int main()
{
    return 0;
}