#include<bits/stdc++.h>
using namespace std;



bool compare(int a, int b, bool ismaxheap)
{
    if (ismaxheap)
        return a > b;
    return a < b;
}
void downheapify(int pi, vector<int> &arr, bool ismaxheap,int n)
{
    //int n = arr.size();
    int maxidx = pi;
    if ((2 * pi) + 1 < n and compare(arr[(2 * pi) + 1], arr[maxidx], ismaxheap))
    {
        maxidx = (2 * pi) + 1;
    }

    if ((2 * pi) + 2 < n and compare(arr[(2 * pi) + 2], arr[maxidx], ismaxheap))
    {
        maxidx = (2 * pi) + 2;
    }
    if (maxidx != pi)
    {
        swap(arr[maxidx], arr[pi]);
        downheapify(maxidx,arr,ismaxheap,n);
    }
}
void constructHeap(vector<int> &arr, bool ismaxheap)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        downheapify(i,arr,ismaxheap,n);
    }
}
void heap_sort(vector<int>& arr,bool ismaxheap)
{
    constructHeap(arr,ismaxheap);
    for(int i=arr.size()-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        downheapify(0,arr,ismaxheap,i);
    }
}

int main()
{
    vector<int> vec = {27, 45, 3, 5, 4, 3, 5, 3, 334, 5, 3, -2};
    heap_sort (vec, true);

    // pq.push(76);
    // pq.push(47);
    // pq.push(23);
    // pq.push(73);
    // pq.push(723);
    // pq.push(756);
    // pq.push(62);

    for(int e:vec)
    {
        cout<<e<<" ";
    }
    return 0;
}