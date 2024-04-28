#include<bits/stdc++.h>
using namespace std;


class comp{
public:
bool operator()(const vector<int> &a,vector<int> &b)const
{
    //return a[0] > b[0];//min pq

    return b[0] > a[0]; //max pq;
}
};

void test(vector<vector<int>>& nums)
{
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    for(auto& vec:nums)
    {
        pq.push(vec);
    }

    while(!pq.empty())
    {
        vector<int> temp = pq.top();
        pq.pop();
        cout << "(" << temp[0] << "," << temp[1] << ")" << endl;

    }
}

int main()
{
    vector<vector<int>> arr{{2, 5}, {1, -1}, {0, -4}, {-6, 3}, {6, 9}, {9, 40}};
    test(arr);

    return 0;
}