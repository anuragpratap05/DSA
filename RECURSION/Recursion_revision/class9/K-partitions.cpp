#include <bits/stdc++.h>
using namespace std;
void Display(vector<vector<int>> &myVec)
{
    for (vector<int> &vec : myVec)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << "| ";
    }
    cout << endl;
}
int KPartitionHelp(int n, int k, vector<vector<int>> &myVec, int num)
{
    if (num > n)
    {
        for (int i = 0; i < k; i++)
        {
            if (myVec[i].size() == 0)
            {
                return 0;
            }
        }
        Display(myVec);
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        myVec[i].push_back(num);
        cnt += KPartitionHelp(n, k, myVec, num + 1);
        myVec[i].pop_back();
        if (myVec[i].size() == 0)
        {
            break;
        }
    }
    return cnt;
}

int KPartition(int n, int k)
{
    vector<vector<int>> myVec(k, vector<int>());
    return KPartitionHelp(n, k, myVec, 1);
}

int main()
{
    cout << KPartition(5, 3);
    return 0;
}