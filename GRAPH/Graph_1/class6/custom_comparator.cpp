#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& vec)
{
    for(vector<int>& v:vec)
    {
        for(int e:v)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}


void sortvector(vector<vector<int>>& vec)
{
    // this function will sort all vectors that are inside vec on basis of index 2.
    sort(vec.begin(),vec.end(), [](vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    });
    display(vec);
}

int main()
{
    vector<vector<int>> vec={{1,2,3},{1,2,-10},{1,2,1},{1,2,6}};
    sortvector(vec);
    return 0;
}