#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &arr)
{
    for (vector<int> &vec : arr)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

void sort_array(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
         {
        if(a[2]==b[2])
        {
            return a[1]>b[1];
        }
        return a[2]<b[2]; });
    display(arr);
}
void display2(vector<pair<int,int>>& vec)
{
    for(auto p:vec)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
}

void sort_pair(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first; });
    //display2(vec);
}

int main()
{
    //vector<vector<int>> arr = {{1, 2, 3}, {1, 6, 1}, {3, 6, 99}, {4, 7, 5}, {6, 4, 3}};
   // sort_array(arr);
    vector<pair<int,int>> vec={{0,19},{1,23},{3,6},{3,5}};
    display2(vec);
    cout<<endl;
    sort_pair(vec);
    cout<<endl;
    display2(vec);
    return 0;
}