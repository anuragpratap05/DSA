#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int p = -1;
    int l = n;
    int c = 0;
    while(c!=l)
    {
        if(a[c]==0)
        {
            p++;
            swap(a[c], a[p]);
            c++;
        }
        else if(a[c]==1)
        {
            c++;
        }
        else{
            l--;
            swap(a[c], a[l]);
        }
    }
}

int main()
{
    return 0;
}