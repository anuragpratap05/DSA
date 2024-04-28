#include<bits/stdc++.h>
using namespace std;



int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    priority_queue<int> pq;
    int n = r;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    return 0;
}