#include<bits/stdc++.h>
using namespace std;

class compator
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        return a[0] > b[0]; // this > other, min PQ.
        // return b[0] > a[0]; // this > other, max PQ.
    }
};

void test2_maxPQ(vector<vector<int>> &arr)
{
    priority_queue<vector<int>, vector<vector<int>>, compator> pq; // Min PQ.
    for (vector<int> &a : arr)
        pq.push(a);

    while (pq.size() != 0)
    {
        vector<int> a = pq.top();
        int i = a[0];
        int j = a[1];
        cout << "(" << i << "," << j << ") " << endl;
        pq.pop();
    }
}

int main()
{
    vector<vector<int>> arr{{2, 5}, {1, -1}, {0, -4}, {-6, 3}, {6, 9}, {9, 40}};
    test2_maxPQ(arr);
    return 0;
}