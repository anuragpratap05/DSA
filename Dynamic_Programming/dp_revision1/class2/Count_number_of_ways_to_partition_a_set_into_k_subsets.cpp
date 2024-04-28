#include <bits/stdc++.h>
using namespace std;

bool checkAllSetsFilled(vector<vector<int>> &sets)
{
    for (vector<int> &curSet : sets)
    {
        if (curSet.size() == 0)
            return false;
    }
    return true;
}

void printSets(vector<vector<int>> &sets)
{
    for (vector<int> &curSet : sets)
    {
        for (int ele : curSet)
            cout << ele;
        cout << " ";
    }
    cout << endl;
}

int countWaysPrintSets(int n, int k, int ele, vector<vector<int>> &sets)
{
    if (ele > n)
    {
        if (checkAllSetsFilled(sets))
        {
            printSets(sets);
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    for (vector<int> &curSet : sets)
    {
        curSet.push_back(ele);
        cnt += countWaysPrintSets(n, k, ele + 1, sets);
        curSet.pop_back();
        if (curSet.size() == 0)
            break;
    }
    return cnt;
}

int countWays(int n, int k)
{
    vector<vector<int>> sets(k, vector<int>());
    return countWaysPrintSets(n, k, 1, sets);
}

int main()
{
    int ways = countWays(10, 4);
    cout << "Ways --> " << ways << endl;
    return 0;
}