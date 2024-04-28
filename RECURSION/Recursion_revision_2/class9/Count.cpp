#include <bits/stdc++.h>
using namespace std;
int waysToPartitionHelper(int n, int k, string s)
{
    if (k == 1)
    {
        return 1;
    }
    if (k == n)
    {
        return n;
    }

    int seperate = waysToPartitionHelper(n - 1, k - 1, "l");
    int with = waysToPartitionHelper(n - 1, k, "r");
    int cnt = seperate + with;
    if (s == "r")
    {
        cnt *= k;
    }
    return cnt;
}

int waysToPartition(int n, int k)
{
    if (n <= k)
    {
        return n == k ? 1 : 0;
    }
    return waysToPartitionHelper(n, k, "");
}

int main()
{
    int n = 4;
    int k = 3;
    cout << waysToPartition(n, k);
    return 0;
}