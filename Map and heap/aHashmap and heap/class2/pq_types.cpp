#include <bits/stdc++.h>
using namespace std;

void max_PQ1(vector<int> &vec)
{
    priority_queue<int> pq;
    for (int e : vec)
    {
        pq.push(e);
    }
    while (!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
}

void min_PQ1(vector<int> &vec)
{
    priority_queue<int, vector<int>, greater<vector<int>>> pq;
    for (int e : vec)
    {
        pq.push(e);
    }
    while (!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
}





int main()
{
   
    return 0;
}