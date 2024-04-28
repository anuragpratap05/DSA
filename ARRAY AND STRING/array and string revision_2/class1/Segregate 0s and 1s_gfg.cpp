#include<bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int n)
{
    int p = -1;
    int c = 0;
    while(c<n)
    {
        if(arr[c]==0)
        {
            p++;
            swap(arr[p], arr[c]);
        }
        else{
            c++;
        }
    }
    
}

int main()
{
    return 0;
}